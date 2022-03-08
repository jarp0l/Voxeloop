#ifndef CORE_INCLUDE_GUIMANAGER_HPP
#define CORE_INCLUDE_GUIMANAGER_HPP


#define FONT_ICON_FILE_NAME "../core/assets/fonts/fa-solid-900.ttf"

#include "../audio/Bindings.hpp"
#include "External/IconsFontAwesome5.h"
#include "WindowManager.hpp"

#include "GLFW/glfw3.h"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <filesystem>
#include <iostream>

class GUIManager {
public:
  GUIManager();
  GUIManager(GLFWwindow *window);

  void init(GLFWwindow *window);

  void getFrame();
  void render();
  void begin();
  void end();

  uint8_t renderMenu(WindowManager *window);
  uint8_t renderSettings(WindowManager *window);
  uint8_t renderAbout(WindowManager *window);

  bool renderBackButton();

  void cleanup();

  ~GUIManager() {}

private:
  // ImVec4: 4D vector used to store clipping rectangles, colors etc.
  ImVec4 clearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
  int displayWidth, displayHeight;
  bool m_open;
};

#endif // CORE_INCLUDE_GUIMANAGER_HPP
