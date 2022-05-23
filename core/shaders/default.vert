#version 450 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;
layout (location = 3) in vec3 aNormal;

out vec3 color;
out vec2 texCoord;
out vec3 normal;

out vec3 currentPos;

uniform float scale;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main() {
    currentPos = vec3(model * vec4(aPos.x * scale, aPos.y * scale, aPos.z * scale, 1.0));
    gl_Position = proj * view * vec4(currentPos, 1.0);
    color = aColor;
    texCoord = aTex; 
    normal = aNormal;
}