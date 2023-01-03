#version 330 core

layout(location=0) in vec3 aPosition;
layout(location=1) in vec4 aColor;

out vec4 vColor;

void main() {
	gl_Position = vec4(aPosition.xyz, 0);

	vColor = vec4(aColor.xyz, 1);;
}
