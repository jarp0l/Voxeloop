#ifndef CORE_INCLUDE_TEMPLATESTATE_HPP
#define CORE_INCLUDE_TEMPLATESTATE_HPP

#include "Common.hpp"
#include "CoreEngine.hpp"
#include "StateMachine.hpp"

class AboutState : public StateMachine {
public:
  void init();
  void cleanup();

  void pause();
  void resume();

  void handleEvents(CoreEngine *engine);
  void update(CoreEngine *engine);
  void draw(CoreEngine *engine);

  static AboutState *instance() { return &m_AboutState; }

protected:
  AboutState() {}

private:
  static AboutState m_AboutState;

  SharedDataRef m_sharedData;
};

#endif // CORE_INCLUDE_TEMPLATESTATE_HPP
