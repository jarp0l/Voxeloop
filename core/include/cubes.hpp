#ifndef VOXELOOP_CUBES_HPP
#define VOXELOOP_CUBES_HPP

#include "Cube.hpp"
#include "LinkedList.hpp"

class Cubes {
public:
  Cubes();
  ~Cubes();

  void addCube();

  void rotate(float r);
  void move(float z);
  void scale(float s);
  void draw();

  void activateShader();
  void clean();
private:
  LinkedList <Cube*> *list;
};

#endif // VOXELOOP_CUBES_HPP
