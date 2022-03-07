#ifndef CORE_INCLUDE_STATEMACHINE_HPP
#define CORE_INCLUDE_STATEMACHINE_HPP

#include "CoreEngine.hpp"

class StateMachine {
public:
  virtual void init() = 0;
  virtual void cleanup() = 0;

  // Not needed in every state, so no need to make pure virtual
  virtual void pause() = 0;
  virtual void resume() = 0;

  virtual void handleEvents(CoreEngine *engine) = 0;
  virtual void update(CoreEngine *engine) = 0;
  virtual void draw(CoreEngine *engine) = 0;

  void changeState(CoreEngine *engine, StateMachine *state) {
    engine->changeState(state);
  }

protected:
  StateMachine() {}
};

#endif // CORE_INCLUDE_STATEMACHINE_HPP
