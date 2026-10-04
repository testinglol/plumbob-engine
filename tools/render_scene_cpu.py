"""CPU mirror of GameMetalView's lot pass (far, medium or near zoom; no lighting) for checking exported scenes without Metal.

Usage: render_scene_cpu.py <scene-N.json> <out.png> [far|medium|near]. Keep outputs out of the repository: scenes and renders
are derived from the game files."""
import json, sys, glob, base64, struct
from pathlib import Path
import numpy as np
from PIL import Image

src = Path(sys.argv[1]); out = sys.argv[2]
zoom = sys.argv[3] if len(sys.argv) > 3 else "medium"
scale = {"far": 0.5, "medium": 1.0, "near": 2.0}[zoom]
scene = json.loads(src.read_text()); d = src.parent
W, H = int(scene["width"] * scale), int(scene["height"] * scale)
color = np.zeros((H, W, 3), np.float32); color[:] = (0.1, 0.1, 0.1)
depth = np.ones((H, W), np.float32)
cache = {}
def tex(i):
    if i in cache: return cache[i]
    t = scene["textures"][i]; raw = (d / t["file"]).read_bytes()
    if t.get("encoding") == "bmp":
        a = np.asarray(Image.open(d / t["file"]).convert("RGBA"), np.float32) / 255
    elif t.get("encoding") == "depth8":
        a = np.frombuffer(raw, np.uint8).reshape(t["height"], t["width"]).astype(np.float32) / 255
    else:
        a = np.frombuffer(raw, np.uint8).reshape(t["height"], t["width"], 4).astype(np.float32) / 255
    cache[i] = a; return a

def raster(tri, attrs):
    """Yield pixel ys, xs and barycentric-interpolated attrs for a screen-space triangle."""
    (x0, y0), (x1, y1), (x2, y2) = tri
    minx, maxx = max(int(np.floor(min(x0, x1, x2))), 0), min(int(np.ceil(max(x0, x1, x2))), W - 1)
    miny, maxy = max(int(np.floor(min(y0, y1, y2))), 0), min(int(np.ceil(max(y0, y1, y2))), H - 1)
    if minx > maxx or miny > maxy: return None
    area = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0)
    if abs(area) < 1e-9: return None
    ys, xs = np.mgrid[miny:maxy + 1, minx:maxx + 1]; px, py = xs + 0.5, ys + 0.5
    w0 = ((x1 - px) * (y2 - py) - (x2 - px) * (y1 - py)) / area
    w1 = ((x2 - px) * (y0 - py) - (x0 - px) * (y2 - py)) / area
    w2 = 1 - w0 - w1
    m = (w0 >= 0) & (w1 >= 0) & (w2 >= 0)
    if not m.any(): return None
    return ys[m], xs[m], [a[0] * w0[m] + a[1] * w1[m] + a[2] * w2[m] for a in attrs]

tv = scene["terrainVertices"]
for k in range(0, len(tv), 3):
    v = tv[k:k + 3]
    r = raster([(p["x"] * scale, p["y"] * scale) for p in v], [[p[c] / 255 for p in v] for c in "rgb"])
    if r: ys, xs, (cr, cg, cb) = r; color[ys, xs] = np.stack([cr, cg, cb], -1)

def items():
    e = [((s.get("level") or 1), (s.get("layer") or 0), s.get("depth", i) if s.get("depth") is not None else i, i, ("s", i)) for i, s in enumerate(scene["sprites"])]
    n = len(scene["sprites"])
    e += [((m.get("level") or 1), (m.get("layer") if m.get("layer") is not None else 1), m["depth"], n + i, ("m", i)) for i, m in enumerate(scene.get("meshes") or [])]
    return [x[4] for x in sorted(e, key=lambda x: x[:4])]

def blend(ys, xs, rgba):
    a = rgba[:, 3:4]; color[ys, xs] = rgba[:, :3] * a + color[ys, xs] * (1 - a)

for kind, i in items():
    if kind == "s":
        s = scene["sprites"][i]
        img = s.get(zoom) if zoom != "medium" else None
        t, dt, rx, ry, rw, rh = (img["texture"], img.get("depthTexture"), s["x"] + img["x"], s["y"] + img["y"], img["width"], img["height"]) if img else (s["texture"], s.get("depthTexture"), s["x"], s["y"], s["width"], s["height"])
        a = tex(t); x0, y0 = round(rx * scale), round(ry * scale); w, h = round(rw * scale), round(rh * scale)
        if w <= 0 or h <= 0: continue
        ys, xs = np.mgrid[max(y0, 0):min(y0 + h, H), max(x0, 0):min(x0 + w, W)]
        if ys.size == 0: continue
        u = (xs + 0.5 - rx * scale) / (rw * scale); v = (ys + 0.5 - ry * scale) / (rh * scale)
        if s["flip"]: u = 1 - u
        tx = np.clip((u * a.shape[1]).astype(int), 0, a.shape[1] - 1); ty = np.clip((v * a.shape[0]).astype(int), 0, a.shape[0] - 1)
        c = a[ty, tx]
        if dt is None:
            ys, xs, c = ys.ravel(), xs.ravel(), c.reshape(-1, 4); blend(ys, xs, c)
        else:
            dm = tex(dt); dd = dm[np.clip((v * dm.shape[0]).astype(int), 0, dm.shape[0] - 1), np.clip((u * dm.shape[1]).astype(int), 0, dm.shape[1] - 1)]
            z = s["depthNear"] + (s["depthFar"] - s["depthNear"]) * dd * (255 / 254)
            m = (c[..., 3] >= 0.25) & (dd < 1) & (z <= depth[ys, xs])
            ys, xs = ys[m], xs[m]; color[ys, xs] = c[m][:, :3]; depth[ys, xs] = z[m]
    else:
        msh = scene["meshes"][i]
        vs = msh["vertices"]
        if isinstance(vs, str):
            f = struct.unpack("<%df" % (len(base64.b64decode(vs)) // 4), base64.b64decode(vs))
            vs = [dict(zip("x y z u v nx ny nz".split(), f[k:k + 8])) for k in range(0, len(f), 8)]
        ti = msh.get({"near": "nearTexture", "far": "farTexture"}.get(zoom, "texture")) or msh["texture"]
        a = tex(ti)
        flat = msh.get("unlit") and not (msh.get("floor") or {}).get("water") and (msh.get("level") or 1) == 1
        for k in range(0, len(vs) - 2, 3):
            v = vs[k:k + 3]
            r = raster([(p["x"] * scale, p["y"] * scale) for p in v], [[p["z"] for p in v], [p["u"] for p in v], [p["v"] for p in v]])
            if not r: continue
            ys, xs, (z, u, vv) = r
            if msh.get("roof") is not None or msh.get("floor") is not None: u, vv = u % 1, vv % 1
            c = a[np.clip((vv * a.shape[0]).astype(int), 0, a.shape[0] - 1), np.clip((u * a.shape[1]).astype(int), 0, a.shape[1] - 1)]
            if flat: blend(ys, xs, c)
            else:
                m = (z <= depth[ys, xs]) & (c[:, 3] > 0.01)
                blend(ys[m], xs[m], c[m]); depth[ys[m], xs[m]] = z[m]

Image.fromarray((np.clip(color, 0, 1) * 255).astype(np.uint8)).save(out)
print(out, W, H)
