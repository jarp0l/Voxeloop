#include "../include/CoreEngine.hpp"
// #include "../include/IntroState.hpp"

int main() {
  CoreEngine *engine = new CoreEngine("Voxeloop");

  engine->run();

  delete engine;
  return EXIT_SUCCESS;
}
