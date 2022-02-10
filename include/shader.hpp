#ifndef VOXELOOP_SHADER_HPP
#define VOXELOOP_SHADER_HPP

// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
// clang-format on
#include "fileHandler.hpp"

class Shader {
 public:
  Shader(const char* vertexfile, const char* fragmentfile);

  void activate();
  void remove();

  GLuint ID;
};

#endif  // VOXELOOP_SHADER_HPP
