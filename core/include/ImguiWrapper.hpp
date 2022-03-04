#ifndef CORE_INCLUDE_IMGUIWRAPPER_HPP
#define CORE_INCLUDE_IMGUIWRAPPER_HPP

// #include "SharedData.hpp"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <string>

class ImguiWrapper {
public:
  ImguiWrapper();
  explicit ImguiWrapper(GLFWwindow *window);

  void init(GLFWwindow *window);

  void getFrame();

  void renderGUI();

  void cleanup();

  ~ImguiWrapper() {}

private:
  // GameDataRef m_gameData;
  GLFWwindow *m_window;
  const std::string m_glslVersion = "#version 130";

  // ImVec4: 4D vector used to store clipping rectangles, colors etc.
  ImVec4 clearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
  int displayWidth, displayHeight;

  // Array of items to diplay on main menu
  // std::string menuItemSelection;
  // bool showNewWindow = false;

  ImGuiStyle *m_style = nullptr;
  ImGuiIO *m_io = nullptr;

  bool m_open;
};

#endif // CORE_INCLUDE_IMGUIWRAPPER_HPP
