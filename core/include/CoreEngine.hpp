#ifndef CORE_INCLUDE_COREENGINE_HPP
#define CORE_INCLUDE_COREENGINE_HPP

#include "Common.hpp"

#include <cstdio>
#include <vector>

class StateMachine;
class CoreEngine {
public:
  void init(const char *title, int width = 640, int height = 480, int bpp = 0,
            bool fullscreen = false);
  void cleanup();

  void changeState(StateMachine *state);
  void pushState(StateMachine *state);
  void popState();

  void handleEvents();
  void update();
  void draw();

  bool isRunning() { return m_isRunning; }
  void quit() { m_isRunning = false; }

  static void key_callback(GLFWwindow *window, int key, int scancode,
                           int action, int modes);

private:
  // the stack of states
  std::vector<StateMachine *> states;

  bool m_isRunning;
  bool m_fullscreen;

  SharedDataRef m_sharedData;
  GLFWwindow *m_window;
};

#endif // CORE_INCLUDE_COREENGINE_HPP
