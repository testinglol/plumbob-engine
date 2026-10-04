#!/bin/sh
# Compiles the SDL_GPU shaders in native/SimsNative/Shaders/sdl to SPIR-V for the SimsSDL client. The .spv outputs are
# committed so building the client needs no shader compiler; rerun this after editing a shader (needs glslangValidator).
set -eu
root=$(cd "$(dirname "$0")/.." && pwd)
source="$root/native/SimsNative/Shaders/sdl"
output="$root/native/SimsNative/Sources/SimsSDL/Shaders"
mkdir -p "$output"
for shader in "$source"/*.vert "$source"/*.frag; do
    name=$(basename "$shader")
    glslangValidator -V --quiet -I"$source" -o "$output/$name.spv" "$shader"
done
