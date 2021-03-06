#ifdef GL_ES
precision highp float;
#endif

#if __VERSION__ >= 140
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
out vec2 TexCoord;
#else
attribute vec3 aPos;
attribute vec2 aTexCoord;
varying vec2 TexCoord;
#endif

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(void)
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    TexCoord = aTexCoord;
}
