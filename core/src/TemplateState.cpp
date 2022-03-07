#include "TemplateState.hpp"

TemplateState TemplateState::m_TemplateState;

void TemplateState::init() {
  std::cout << "[INFO] TemplateState initialized\n";
}

void TemplateState::cleanup() { std::cout << "[INFO] TemplateState cleaned\n"; }

void TemplateState::pause() { std::cout << "[INFO] TemplateState paused\n"; }

void TemplateState::resume() { std::cout << "[INFO] TemplateState resumed\n"; }

void TemplateState::handleEvents(CoreEngine *engine) {
  // SDL_Event event;

  // if (SDL_PollEvent(&event)) {
  //   switch (event.type) {
  //   case SDL_QUIT:
  //     engine->quit();
  //     break;

  //   case SDL_KEYDOWN:
  //     switch (event.key.keysym.sym) {
  //     // case SDLK_SPACE:
  //     //   engine->changeState(CTemplateState::instance());
  //     //   break;

  //     case SDLK_ESCAPE:
  //       engine->quit();
  //       break;
  //     }
  //     break;
  //   }
  // }
}

void TemplateState::update(CoreEngine *engine) {}

void TemplateState::draw(CoreEngine *engine) {
  m_gameData->window.update();
  m_gameData->window.clear();

  // draw all the stuffs here

  // m_gameData->gui.getFrame();
  // m_gameData->gui.renderMenu(&m_gameData->window);

  m_gameData->window.render();
}
