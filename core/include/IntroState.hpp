#ifndef CORE_INCLUDE_INTROSTATE_HPP
#define CORE_INCLUDE_INTROSTATE_HPP

#include "State.hpp"
// #include "CoreEngine.hpp"
#include "ImguiWrapper.hpp"
#include "SharedData.hpp"

class IntroState : public State {
public:
  IntroState(GameDataRef gameData);
  void init();
  void update();
  void draw();
  // void handleInput();
  virtual ~IntroState(){};

private:
  GameDataRef m_gameData;
  ImguiWrapper m_gui;
};

#endif // CORE_INCLUDE_INTROSTATE_HPP
