#version 330
layout (location = 0) in vec2 pos;

uniform mat4 model;
uniform mat4 projection;

void main()
{
	gl_Position = projection * model * vec4(pos, 0.0, 1.0);
}