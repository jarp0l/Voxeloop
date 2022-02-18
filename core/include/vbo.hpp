#ifndef CORE_INCLUDE_VBO_HPP
#define CORE_INCLUDE_VBO_HPP

#include <glad/gl.h>

class VBO {
public:
  GLuint ID;
  VBO(GLfloat *vertices, GLsizeiptr size);


  void bind();
  void unbind();
  void remove();
};

#endif // CORE_INCLUDE_VBO_HPP
