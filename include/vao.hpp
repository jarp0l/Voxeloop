#ifndef VOXELOOP_VAO_HPP
#define VOXELOOP_VAO_HPP

#include <glad/gl.h>

#include <vbo.hpp>

class VAO {
 public:
  VAO();
  GLuint ID;

  void linkVBO(VBO vbo, GLuint layout);

  void bind();
  void unbind();
  void remove();
};

#endif  // VOXELOOP_VAO_HPP
