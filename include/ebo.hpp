#ifndef VOXELOOP_EBO_HPP
#define VOXELOOP_EBO_HPP

#include <glad/gl.h>

class EBO {
 public:
  EBO(GLuint* indices, GLsizeiptr size);
  GLuint ID;

  void bind();
  void unbind();
  void remove();
};

#endif  // VOXELOOP_EBO_HPP
