#version 450 core

layout (location=0) in vec3 position;
layout (location=1) in vec3 color;
layout (location=2) in vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec4 v_color;

void main()
{
    gl_Position = vec4(position, 1.0);
    v_color = vec4(color,1.0);
}

