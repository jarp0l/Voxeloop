#ifndef VOXELOOP_VOXELOOP_HPP
#define VOXELOOP_VOXELOOP_HPP

// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
// clang-format on
#include "Audio.hpp"
#include "Common.hpp"
#include "Cubes.hpp"
// #include "LightSource.hpp"
#include "LinkedList.hpp"
#include "WindowManager.hpp"

class Voxeloop {
public:
  static void key_callback(GLFWwindow *window, int key, int scancode,
                           int action, int mods);

  void init(GLFWwindow *window);
  void run();
  void cleanup();

private:
  GLFWwindow *m_window;
  SharedDataRef m_sharedData;
  WindowManager *win;

  Cubes *m_cubes;
  Audio *m_audio;
  // LightSource *m_lightsource;

  float m_mvmt;
  float m_scale;
  double m_prevTime;

private:
  void loop();
};

#endif // CORE_INCLUDE_VOXELOOP_HPP
