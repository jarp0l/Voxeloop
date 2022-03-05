#include "Main.hpp"

int main() {
  Voxeloop *voxeloop = new Voxeloop;
  voxeloop->run();
  delete voxeloop;
  return EXIT_SUCCESS;
}
