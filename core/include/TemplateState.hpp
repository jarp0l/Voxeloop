#ifndef CORE_INCLUDE_TEMPLATESTATE_HPP
#define CORE_INCLUDE_TEMPLATESTATE_HPP

#include "Common.hpp"
#include "CoreEngine.hpp"
#include "StateMachine.hpp"

class TemplateState : public StateMachine {
public:
  void init();
  void cleanup();

  void pause();
  void resume();

  void handleEvents(CoreEngine *engine);
  void update(CoreEngine *engine);
  void draw(CoreEngine *engine);

  static TemplateState *instance() { return &m_TemplateState; }

protected:
  TemplateState() {}

private:
  static TemplateState m_TemplateState;

  GameDataRef m_gameData;
};

#endif // CORE_INCLUDE_TEMPLATESTATE_HPP
