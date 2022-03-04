#include "../include/CoreEngine.hpp"
// #include "../include/IntroState.hpp"

int main() {
  CoreEngine *engine = new CoreEngine("Voxeloop");
  engine->run();

  // engine.init();  // initialize engine

  // while (engine.isRunning()) {
  //   engine.handleEvents();
  //   engine.update();
  //   engine.draw();
  // }

  // engine.cleanup();

  delete engine;

  return 0;
}
