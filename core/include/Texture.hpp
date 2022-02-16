#ifndef CORE_INCLUDE_TEXTURE_HPP
#define CORE_INCLUDE_TEXTURE_HPP

#include "Shader.hpp"

class Texture {
public:
  GLuint ID;
  GLenum type;
  Texture(const char *image, GLenum texType, GLenum slot, GLenum format,
          GLenum pixelType);

  void texUint(Shader *shader, const char *uniform, GLuint uint);
  void bind();
  void unbind();
  void remove();
};

#endif // CORE_INCLUDE_TEXTURE_HPP
