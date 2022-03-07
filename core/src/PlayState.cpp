#include "PlayState.hpp"
#include "Voxeloop.hpp"

PlayState PlayState::m_PlayState;

void PlayState::init() {
  voxeloop = new Voxeloop;

  voxeloop->init(m_gameData->window.getWindow());

  // m_mvmt = 0.0f;
  // m_scale = 1.0f;

  // m_audio = new Audio;
  // m_cubes = new Cubes;

  // // Setup rotation
  // m_prevTime = glfwGetTime();

  // glfwSetWindowUserPointer(window, this);

  std::cout << "[INFO] PlayState initialized\n";
}

void PlayState::cleanup() {
  // delete m_audio;
  // delete m_cubes;
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
  m_gameData->window.update();
  m_gameData->window.clear();

  // draw all the stuffs here

  // m_gameData->gui.getFrame();
  // m_gameData->gui.renderMenu(&m_gameData->window);
  voxeloop->run();

  m_gameData->gui.getFrame();
  if (m_gameData->gui.renderBackButton())
    engine->popState();

  m_gameData->window.render();
}
