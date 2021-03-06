#ifndef CORE_INCLUDE_SHADER_HPP
#define CORE_INCLUDE_SHADER_HPP

// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
// clang-format on
#include "FileHandler.hpp"

class Shader {
public:
  Shader(const char *vertexfile, const char *fragmentfile);


  void activate();
  void remove();

  GLuint ID;
};

#endif // CORE_INCLUDE_SHADER_HPP
