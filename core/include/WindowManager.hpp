#ifndef CORE_INCLUDE_WINDOWMANAGER_HPP
#define CORE_INCLUDE_WINDOWMANAGER_HPP

// We need to turn clang-format off here to prevent it from including glfw
// before glad
// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
// clang-format on
#include <iostream>

class WindowManager {
public:
  void create(const char *title, int width, int height);
  bool isCloseRequested();
  void close(); // close window
  static void clear();
  void update();
  void render();

  void cleanup();

  static GLFWwindow *getWindow();
  static int getWidth();
  static int getHeight();

private:
  static GLFWwindow *m_window;
  static int m_width;
  static int m_height;

  int m_glMajor = 4;
  int m_glMinor = 5;
};

#endif // CORE_INCLUDE_WINDOWMANAGER_HPP
