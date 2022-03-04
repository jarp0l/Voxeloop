#include "../include/CoreEngine.hpp"

CoreEngine::CoreEngine(std::string title, int width, int height) {
  m_gameData->window.create(title, width, height);
  // m_gameData->gui.init();
  m_gameData->machine.addState(StateRef(new IntroState(m_gameData)));
}

void CoreEngine::run() {
  while (!m_gameData->window.isCloseRequested()) {
    m_gameData->machine.processStateChanges();

    m_gameData->machine.getActiveState()->update();

    m_gameData->machine.getActiveState()->draw();
  }
}

CoreEngine::~CoreEngine() {
  std::cout << "[INFO] DESTROYING COREENGINE OBJECT" << std::endl;
  m_gameData->window.cleanup();
}