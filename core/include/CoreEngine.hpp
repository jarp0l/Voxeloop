#ifndef CORE_INCLUDE_COREENGINE_HPP
#define CORE_INCLUDE_COREENGINE_HPP

#include "IntroState.hpp"
#include "SharedData.hpp"

class CoreEngine {
public:
  CoreEngine(std::string title, int width = 640, int height = 480) {
    m_gameData->window.create(title, width, height);
    // m_gameData->gui.init();
    m_gameData->machine.addState(StateRef(new IntroState(m_gameData)));
  }

  ~CoreEngine() {
    m_gameData->window.cleanup();
    // m_gameData->gui.cleanup();
  }

  // void init();
  void run();

private:
  GameDataRef m_gameData =
      std::make_shared<GameData>(); /// The shared pointer of game data
};

#endif // CORE_INCLUDE_COREENGINE_HPP
