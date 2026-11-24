#version 450

// One triangle that covers the target; the post passes read their inputs with texelFetch at gl_FragCoord.
void main() {
    vec2 corner = vec2((gl_VertexIndex << 1) & 2, gl_VertexIndex & 2);
    gl_Position = vec4(corner * 2.0 - 1.0, 0.0, 1.0);
}
