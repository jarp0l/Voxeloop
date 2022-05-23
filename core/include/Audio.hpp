#ifndef VOXELOOP_AUDIO_HPP
#define VOXELOOP_AUDIO_HPP

#include "../assets/audio/Bindings.hpp"
#include "Tree.hpp"

#include <miniaudio.h>

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unistd.h>

class Audio {
public:
  Audio();
  ~Audio();

  void setAudio(char s, std::string path);
  void play(char s);

  void addAudio(char key, float mvmt);
  void updateList();
  void traverseList(float mvmt);

private:
  ma_engine engine;
  ma_result result;
  std::map<char, ma_sound> sounds;

  Tree *tree;

  TreeNode *currentSound;
};

#endif // VOXELOOP_AUDIO_HPP
