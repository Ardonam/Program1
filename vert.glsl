#version 330

in vec2 position;
in vec3 color_in;
uniform mat4 p_matrix;
out vec3 frag_color;

void main() {
  gl_Position = p_matrix * vec4(position.x, position.y, 0, 1);
  frag_color = color_in;
}
