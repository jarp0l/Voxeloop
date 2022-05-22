#version 450 core
out vec4 FragColor;

in vec3 color;
in vec2 texCoord;
in vec3 normal;
in vec3 currentPos;

uniform sampler2D tex0;
uniform vec4 lightColor;
uniform vec3 lightPos;

void main() {
    // Ambient lighting
    float ambient = 0.2f;

    // Diffused lighting
    vec3 normalizedNormal = normalize(normal);
    vec3 lightDirection = normalize(lightPos - currentPos);
    float diffuse = max(dot(normal, lightDirection), 0.0f);

    // Specular lighting
	float specularLight = 0.70f;
    vec3 camPos = vec3(0.3f, 0.3f, -2.0f);
	vec3 viewDirection = normalize(camPos - currentPos);
	vec3 reflectionDirection = reflect(-lightDirection, normal);
	float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 8);
	float specular = specAmount * specularLight;

    vec4 light = lightColor * (ambient + diffuse + specular);

    FragColor = texture(tex0, texCoord) * light;
}