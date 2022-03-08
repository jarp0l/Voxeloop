#include "MenuState.hpp"

MenuState MenuState::m_menuState;

void MenuState::init() { std::cout << "[INFO] MenuState initialized\n"; }

void MenuState::cleanup() { std::cout << "[INFO] MenuState cleaned\n"; }

void MenuState::pause() { std::cout << "[INFO] MenuState paused\n"; }

void MenuState::resume() { std::cout << "[INFO] MenuState resumed\n"; }

void MenuState::handleEvents(CoreEngine *engine) {}

void MenuState::update(CoreEngine *engine) {}

void MenuState::draw(CoreEngine *engine) {
  m_sharedData->gui.begin();
  nextState = m_sharedData->gui.renderMenu(&m_sharedData->window);

  switch (nextState) {
  case 0:
    break;
  case 1:
    engine->pushState(PlayState::instance());
    break;
  case 2:
    engine->pushState(SettingsState::instance());
    break;
  case 3:
    engine->pushState(AboutState::instance());
    break;
    // case 4:
    //   engine->changeState(PlayState::instance());
    //   break;
    // case 15:
    //   break;
  }

  m_sharedData->gui.end();
}
