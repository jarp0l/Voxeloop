#ifndef CORE_INCLUDE_MENUSTATE_HPP
#define CORE_INCLUDE_MENUSTATE_HPP

#include "AboutState.hpp"
#include "Common.hpp"
#include "CoreEngine.hpp"
#include "PlayState.hpp"
#include "StateMachine.hpp"
// #include "...State.hpp"

class MenuState : public StateMachine {
public:
  void init();
  void cleanup();

  void pause();
  void resume();

  void handleEvents(CoreEngine *engine);
  void update(CoreEngine *engine);
  void draw(CoreEngine *engine);

  static MenuState *instance() { return &m_menuState; }

protected:
  MenuState() {}

private:
  static MenuState m_menuState;

  GameDataRef m_gameData;
  uint8_t nextState;
};

#endif // CORE_INCLUDE_MENUSTATE_HPP
