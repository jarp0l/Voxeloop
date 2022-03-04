#ifndef CORE_INCLUDE_COREENGINE_HPP
#define CORE_INCLUDE_COREENGINE_HPP

#include "IntroState.hpp"
#include "SharedData.hpp"

class CoreEngine {
public:
  CoreEngine(std::string title, int width = 640, int height = 480);

  ~CoreEngine();

  // void init();
  void run();

private:
  GameDataRef m_gameData =
      std::make_shared<GameData>(); /// The shared pointer of game data
};

#endif // CORE_INCLUDE_COREENGINE_HPP
