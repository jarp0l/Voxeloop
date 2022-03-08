#ifndef CORE_INCLUDE_COMMON_HPP
#define CORE_INCLUDE_COMMON_HPP

#include "GUIManager.hpp"
#include "WindowManager.hpp"

#include <memory>

struct GameData {
  WindowManager window;
  GUIManager gui;
};

typedef std::shared_ptr<GameData> SharedDataRef;


#endif // CORE_INCLUDE_COMMON_HPP
