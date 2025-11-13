#version 460 core
out vec4 FragColor;

in vec3 VertCol;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourTexture, TexCoord);
};

