#version 330 core

layout(location=0) in vec3 position;

void main() {
	gl_Position = vec4(position.xyz, 0);
}

#version 330 core

uniform vec4 u_Color;

out vec4 color;

void main() {
	color = u_Color;
}