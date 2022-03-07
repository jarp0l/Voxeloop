#include "MenuState.hpp"

MenuState MenuState::m_menuState;

void MenuState::init() { std::cout << "[INFO] MenuState initialized\n"; }

void MenuState::cleanup() { std::cout << "[INFO] MenuState cleaned\n"; }

void MenuState::pause() { std::cout << "[INFO] MenuState paused\n"; }

void MenuState::resume() { std::cout << "[INFO] MenuState resumed\n"; }

void MenuState::handleEvents(CoreEngine *engine) {
  // SDL_Event event;

  // if (SDL_PollEvent(&event)) {
  //   switch (event.type) {
  //   case SDL_QUIT:
  //     engine->quit();
  //     break;

  //   case SDL_KEYDOWN:
  //     switch (event.key.keysym.sym) {
  //     // case SDLK_SPACE:
  //     //   engine->changeState(CMenuState::instance());
  //     //   break;

  //     case SDLK_ESCAPE:
  //       engine->quit();
  //       break;
  //     }
  //     break;
  //   }
  // }
}

void MenuState::update(CoreEngine *engine) {}

void MenuState::draw(CoreEngine *engine) {
  m_gameData->window.update();
  m_gameData->window.clear();

  m_gameData->gui.getFrame();
  nextState = m_gameData->gui.renderMenu(&m_gameData->window);

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

  m_gameData->window.render();
}
