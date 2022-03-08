#ifndef CORE_INCLUDE_VAO_HPP
#define CORE_INCLUDE_VAO_HPP

#include <glad/gl.h>

#include "VBO.hpp"

class VAO {
public:
  VAO();
  GLuint ID;

  void linkAttrib(VBO &vbo, GLuint layout, GLuint numComponents, GLenum type,
                  GLsizeiptr stride, void *offset);

  void bind();
  void unbind();
  void remove();
};

#endif // CORE_INCLUDE_VAO_HPP
