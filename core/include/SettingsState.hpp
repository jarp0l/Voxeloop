#ifndef CORE_INCLUDE_SETTINGSSTATE_HPP
#define CORE_INCLUDE_SETTINGSSTATE_HPP

#include "Common.hpp"
#include "CoreEngine.hpp"
#include "StateMachine.hpp"

class SettingsState : public StateMachine {
public:
  void init();
  void cleanup();

  void pause();
  void resume();

  void handleEvents(CoreEngine *engine);
  void update(CoreEngine *engine);
  void draw(CoreEngine *engine);

  static SettingsState *instance() { return &m_AboutState; }

protected:
  SettingsState() {}

private:
  static SettingsState m_AboutState;

  GameDataRef m_gameData;
};

#endif // CORE_INCLUDE_SETTINGSSTATE_HPP
