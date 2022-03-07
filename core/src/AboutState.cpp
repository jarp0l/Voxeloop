#include "AboutState.hpp"

AboutState AboutState::m_AboutState;

void AboutState::init() { std::cout << "[INFO] AboutState initialized\n"; }

void AboutState::cleanup() { std::cout << "[INFO] AboutState cleaned\n"; }

void AboutState::pause() { std::cout << "[INFO] AboutState paused\n"; }

void AboutState::resume() { std::cout << "[INFO] AboutState resumed\n"; }

void AboutState::handleEvents(CoreEngine *engine) {
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

void AboutState::update(CoreEngine *engine) {}

void AboutState::draw(CoreEngine *engine) {
  m_gameData->window.update();
  m_gameData->window.clear();

  m_gameData->gui.getFrame();
  if (m_gameData->gui.renderBackButton())
    engine->popState();

  m_gameData->window.render();
}
