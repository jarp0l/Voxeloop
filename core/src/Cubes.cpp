#include "Cubes.hpp"


Cubes::Cubes() { list = new LinkedList<Cube *>; 
isPerspective = true;}

Cubes::~Cubes() { delete list; }

void Cubes::addCube() {
  Cube *cube = new Cube;
  cube->setTexUinform();
  cube->setScaleUniform();
  list->addData(cube);
}

void Cubes::rotate(float r) {
  if (list->head == nullptr)
    return;
  struct Node<Cube *> *thead = list->head;
  while (thead != nullptr) {
    thead->data->rotate(r);
    thead = thead->next;
  }
}

void Cubes::move(float z) {
  if (list->head == nullptr)
    return;
  struct Node<Cube *> *thead = list->head;
  while (thead != nullptr) {
    thead->data->move(z);
    thead = thead->next;
  }
}

void Cubes::scale(float s) {
  if (list->head == nullptr)
    return;
  struct Node<Cube *> *thead = list->head;
  while (thead != nullptr) {
    thead->data->scale(s);
    thead = thead->next;
  }
}

void Cubes::draw() {
  setPerspective(isPerspective);
  if (list->head == nullptr)
    return;
  struct Node<Cube *> *thead = list->head;
  while (thead != nullptr) {
    thead->data->draw();
    thead = thead->next;
  }
}

void Cubes::activateShader() {
  if (list->head == nullptr)
    return;
  struct Node<Cube *> *thead = list->head;
  while (thead != nullptr) {
    thead->data->activateShader();
    thead = thead->next;
  }
}

void Cubes::setPerspective(bool view) {
  if (list->head == nullptr)
    return;
  struct Node<Cube *> *thead = list->head;
  while (thead != nullptr) {
    thead->data->setPrespective(view);
    thead = thead->next;
  }
}

void Cubes::setPerVal(bool view) {
  isPerspective = view;
}

void Cubes::clean() {}
