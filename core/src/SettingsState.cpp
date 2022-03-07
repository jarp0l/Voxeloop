#include "SettingsState.hpp"

SettingsState SettingsState::m_AboutState;

void SettingsState::init() {
  std::cout << "[INFO] SettingsState initialized\n";
}

void SettingsState::cleanup() { std::cout << "[INFO] SettingsState cleaned\n"; }

void SettingsState::pause() { std::cout << "[INFO] SettingsState paused\n"; }

void SettingsState::resume() { std::cout << "[INFO] SettingsState resumed\n"; }

void SettingsState::handleEvents(CoreEngine *engine) {
  // SDL_Event event;

  // if (SDL_PollEvent(&event)) {
  //   switch (event.type) {
  //   case SDL_QUIT:
  //     engine->quit();
  //     break;

  //   case SDL_KEYDOWN:
  //     switch (event.key.keysym.sym) {
  //     // case SDLK_SPACE:
  //     //   engine->changeState(CAboutState::instance());
  //     //   break;

  //     case SDLK_ESCAPE:
  //       engine->quit();
  //       break;
  //     }
  //     break;
  //   }
  // }
}

void SettingsState::update(CoreEngine *engine) {}

void SettingsState::draw(CoreEngine *engine) {
  // draw all the stuffs here
  m_gameData->gui.getFrame();

  if (m_gameData->gui.renderBackButton())
    engine->popState();

  m_gameData->gui.renderSettings();
}
