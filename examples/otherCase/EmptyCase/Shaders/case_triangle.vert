#version 450 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec4 aColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 project;

out vec4 vColor;

void main()
{
    gl_Position = project * view * model * vec4(aPos, 1.0);
    vColor = aColor;
}


