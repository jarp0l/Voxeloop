#ifndef CORE_INCLUDE_GUIMANAGER_HPP
#define CORE_INCLUDE_GUIMANAGER_HPP

#define FONT_ICON_FILE_NAME "../assets/fonts/fa-solid-900.ttf"

#include "WindowManager.hpp"

#include "External/IconsFontAwesome5.h"
#include "GLFW/glfw3.h"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <iostream>

class GUIManager {
public:
  GUIManager();
  GUIManager(GLFWwindow *window);

  void init(GLFWwindow *window);

  void getFrame();

  void render();
  uint8_t renderMenu(WindowManager *window);
  void renderSettings();
  void renderAbout();
  bool renderBackButton();

  void cleanup();

  ~GUIManager() {}

private:
  // char m_glslVersion[] = "#version 130";

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

#endif // CORE_INCLUDE_GUIMANAGER_HPP
