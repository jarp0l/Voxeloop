#ifndef VOXELOOP_TEXTURE_HPP
#define VOXELOOP_TEXTURE_HPP


#include "shader.hpp"

class Texture {
public:
  GLuint ID;
  GLenum type;
  Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

  void texUint(Shader* shader, const char* uniform, GLuint uint);
  void bind();
  void unbind();
  void remove();
};

#endif // VOXELOOP_TEXTURE_HPP
