#ifndef CORE_INCLUDE_COMMON_HPP
#define CORE_INCLUDE_COMMON_HPP

#include "WindowManager.hpp"
#include "GUIManager.hpp"

#include <memory>

struct GameData {
  WindowManager window;
  GUIManager gui;
  // InputManager input;
  // AssetManager assets;
};

typedef std::shared_ptr<GameData> GameDataRef;

#endif // CORE_INCLUDE_COMMON_HPP
