#ifndef CORE_INCLUDE_JARP0L_HPP
#define CORE_INCLUDE_JARP0L_HPP

// We need to turn clang-format off here to prevent it from including glfw
// before glad
// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
// clang-format on
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <cmath>
#include <filesystem>
#include <iostream>
#include <string>

// #include "Shader.hpp"
// #include "Texture.hpp"
// #include "ebo.hpp"
// #include "vao.hpp"
// #include "vbo.hpp"

class RenderWindow {
private:
  int _windowWidth, _windowHeight;
  std::string _glslVersion;
  GLFWwindow *_window;

public:
  Window(int windowWidth = 800, int windowHeight = 800,
         std::string title = "Voxeloop");

  bool initGLAD();
  bool initGLFW(int windowWidth, int windowHeight, const std::string &title);
  bool initDearImGui();

  ///
  /// @brief Cleanup GLFW window along with glad and Dear ImGui setups
  ///
  void cleanup();

  ///
  /// @brief Destroy Window object after calling teardown() function
  ///
  ~Window();
};

///
/// @brief Function for GLFW error callback
///
/// @param error Error code
/// @param description Description of the error
static void glfwErrorCallback(int error, const char *description);

#endif // CORE_INCLUDE_JARP0L_HPP
