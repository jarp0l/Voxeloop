#include "PlayState.hpp"
#include "Voxeloop.hpp"

PlayState PlayState::m_PlayState;

void PlayState::init() {
  voxeloop = new Voxeloop;

  voxeloop->init(m_sharedData->window.getWindow());

  std::cout << "[INFO] PlayState initialized\n";
}

void PlayState::cleanup() {
  voxeloop->cleanup();
  delete voxeloop;

  std::cout << "[INFO] PlayState cleaned\n";
}

void PlayState::pause() { std::cout << "[INFO] PlayState paused\n"; }

void PlayState::resume() { std::cout << "[INFO] PlayState resumed\n"; }

void PlayState::handleEvents(CoreEngine *engine) {
  // SDL_Event event;

  // if (SDL_PollEvent(&event)) {
  //   switch (event.type) {
  //   case SDL_QUIT:
  //     engine->quit();
  //     break;

  //   case SDL_KEYDOWN:
  //     switch (event.key.keysym.sym) {
  //     // case SDLK_SPACE:
  //     //   engine->changeState(CPlayState::instance());
  //     //   break;

  //     case SDLK_ESCAPE:
  //       engine->quit();
  //       break;
  //     }
  //     break;
  //   }
  // }
}

void PlayState::update(CoreEngine *engine) {}

void PlayState::draw(CoreEngine *engine) {
  voxeloop->run();

  m_sharedData->gui.begin();
  if (m_sharedData->gui.renderBackButton())
    engine->popState();
}
