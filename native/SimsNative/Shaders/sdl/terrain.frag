#version 450
layout(location = 0) in vec4 inColor;
layout(location = 1) in vec2 inCoordinate;
layout(location = 0) out vec4 color;
void main() {
    float detail = fract(sin(dot(floor(inCoordinate), vec2(12.9898, 78.233))) * 43758.5453);
    color = vec4(inColor.rgb * (0.9 + detail * 0.2), 1.0);
}
