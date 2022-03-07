#include "Voxeloop.hpp"

Voxeloop::Voxeloop(int windowWidth, int windowHeight,
                   const std::string &title) {
  this->_data->_window.create(sf::VideoMode(width, height), title,
                              sf::Style::Titlebar | sf::Style::Close);
  this->_data->machine.addState(StateRef(new SplashScreen(this->_data)));

  this->run();
}