#include "SettingsState.hpp"

SettingsState SettingsState::m_AboutState;

void SettingsState::init() {
  std::cout << "[INFO] SettingsState initialized\n";
}

void SettingsState::cleanup() { std::cout << "[INFO] SettingsState cleaned\n"; }

void SettingsState::pause() { std::cout << "[INFO] SettingsState paused\n"; }

void SettingsState::resume() { std::cout << "[INFO] SettingsState resumed\n"; }

void SettingsState::handleEvents(CoreEngine *engine) {}

void SettingsState::update(CoreEngine *engine) {}

void SettingsState::draw(CoreEngine *engine) {
  // draw all the stuffs here
  m_gameData->gui.begin();

  if (m_gameData->gui.renderSettings(&m_gameData->window) == 1)
    engine->popState();

  m_gameData->gui.end();
}
