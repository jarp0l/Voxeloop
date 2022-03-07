#include "CoreEngine.hpp"
#include "MenuState.hpp"

int main() {
  CoreEngine *engine = new CoreEngine;

  const char *title = "Voxeloop";
  int width = 800;
  int height = 800;
  // initialize the engine
  engine->init(title, width, height);

  // load the intro state
  engine->changeState(MenuState::instance());

  // main loop
  while (engine->isRunning()) {
    engine->handleEvents();
    engine->update();
    engine->draw();
  }

  // cleanup the engine and everything else
  engine->cleanup();
  delete engine;
  return EXIT_SUCCESS;
}
