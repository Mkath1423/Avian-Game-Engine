#version 330 core

layout(location = 0) in vec3 aposition;
layout(location = 1) in vec4 aColor;

out vec4 fColor;

void main() {
	gl_Position = vec4(aposition.xyz, 0);

	fColor = aColor;
}

#version 330 core

in vec4 aColor;

out vec4 color;

void main() {
	color = aColor;
}