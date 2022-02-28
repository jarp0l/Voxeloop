#ifndef CORE_INCLUDE_EBO_HPP
#define CORE_INCLUDE_EBO_HPP

#include <glad/gl.h>

class EBO {

public:
  EBO(GLuint *indices, GLsizeiptr size);
  EBO();
  GLuint ID;
  void setup(GLuint *indices, GLsizeiptr size);
  void bind();
  void unbind();
  void remove();
};

#endif // CORE_INCLUDE_EBO_HPP
