#ifndef CORE_INCLUDE_VOXELOOP_HPP
#define CORE_INCLUDE_VOXELOOP_HPP

#include "StateMachine.hpp"
#include <memory>

struct VoxeloopData {
  StateMachine machine;
  // InputManager input;
  // AssetManager assets;
};

typedef std::shared_ptr<VoxeloopData> VoxeloopDataRef;

///
/// @brief Class where app loop is processed
///
class Voxeloop {
public:
  Voxeloop(int windowWidth, int windowHeight, const std::string &title);
  // ~Voxeloop();

private:
  void run();
  VoxeloopDataRef _data = std::make_shared<VoxeloopData>();
};

#endif // CORE_INCLUDE_VOXELOOP_HPP
