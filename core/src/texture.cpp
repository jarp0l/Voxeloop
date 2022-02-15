#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>
#include "texture.hpp"


Texture::Texture(const char *image, GLenum texType, GLenum slot, GLenum format,
                 GLenum pixelType) {
  type = texType;

  // Texture
  int widthImg, heightImg, numColCh;
//  stbi_set_flip_vertically_on_load(true);
  unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

  glGenTextures(1, &ID);

  // Add texture to texture unit
  glActiveTexture(slot);
  glBindTexture(texType, ID);

  /// Set texture parameters
  // Filter
  glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  // Wrap
  glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

  // Borders
  float flatColor[] = {1.0f, 1.0f, 1.0f, 1.0f}; // Black Border
  glTexParameterfv(texType, GL_TEXTURE_BORDER_COLOR, flatColor);

  // Setup Image
  glTexImage2D(texType, 0, format, widthImg, heightImg, 0, format, pixelType, bytes);

  // Generate Mipmap
  glGenerateMipmap(texType);

  // Free data and unbind textures
  stbi_image_free(bytes);
  glBindTexture(texType, 0);
}

void Texture::texUint(Shader* shader, const char *uniform, GLuint uint) {
  GLuint tex0Uni = glGetUniformLocation(shader->ID, uniform);
  shader->activate();
  glUniform1i(tex0Uni, uint);
}

void Texture::bind() {
  glBindTexture(type, ID);
}

void Texture::unbind() {
  glBindTexture(type, 0);
}

void Texture::remove() {
  glDeleteTextures(1, &ID);
}
