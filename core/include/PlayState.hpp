#ifndef CORE_INCLUDE_PLAYSTATE_HPP
#define CORE_INCLUDE_PLAYSTATE_HPP

#include "Common.hpp"
#include "CoreEngine.hpp"
#include "StateMachine.hpp"
#include "Voxeloop.hpp"

class PlayState : public StateMachine {
public:
  void init();
  void cleanup();

  void pause();
  void resume();

  void handleEvents(CoreEngine *engine);
  void update(CoreEngine *engine);
  void draw(CoreEngine *engine);

  static PlayState *instance() { return &m_PlayState; }
  // static void key_callback(GLFWwindow *window, int key, int scancode,
  //  int action, int mods);

protected:
  PlayState() {}

private:
  static PlayState m_PlayState;

  GameDataRef m_gameData;
  Voxeloop *voxeloop;

private:
  void loop();
};

#endif // CORE_INCLUDE_PLAYSTATE_HPP
