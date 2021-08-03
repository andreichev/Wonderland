#ifdef GL_ES
precision highp float;
#endif

#if __VERSION__ >= 140
in vec2 TexCoord;
out vec4 fragColor;
#else
varying vec2 TexCoord;
#endif

uniform sampler2D texture1;

void main(void)
{
#if __VERSION__ >= 140
    fragColor = texture(texture1, TexCoord);
#else
    gl_FragColor = texture2D(texture1, TexCoord);
#endif
}
