#ifndef VOXELOOP_VBO_HPP
#define VOXELOOP_VBO_HPP

#include <glad/gl.h>

class VBO {
 public:
  GLuint ID;
  VBO(GLfloat* vertices, GLsizeiptr size);

  void bind();
  void unbind();
  void remove();
};

#endif  // VOXELOOP_VBO_HPP
