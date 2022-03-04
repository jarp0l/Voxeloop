#include "../include/CoreEngine.hpp"

void CoreEngine::run() {
  while (!m_gameData->window.isCloseRequested()) {
    m_gameData->machine.processStateChanges();

    m_gameData->machine.getActiveState()->update();

    m_gameData->machine.getActiveState()->draw();
  }
}
