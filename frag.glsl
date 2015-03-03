#version 330


out vec4 color_out;
in vec3 frag_color;

void main() {
  color_out = vec4(frag_color, 1.0);
}
