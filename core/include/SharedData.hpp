#ifndef CORE_INCLUDE_SHAREDDATA_HPP
#define CORE_INCLUDE_SHAREDDATA_HPP

// #include "ImguiWrapper.hpp"
#include "StateMachine.hpp"
#include "Window.hpp"

struct GameData {
  Window window;
  // ImguiWrapper gui;
  StateMachine machine;
  // InputManager input;
  // AssetManager assets;
};

typedef std::shared_ptr<GameData> GameDataRef;

#endif // CORE_INCLUDE_SHAREDDATA_HPP
