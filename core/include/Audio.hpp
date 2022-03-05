#ifndef VOXELOOP_AUDIO_HPP
#define VOXELOOP_AUDIO_HPP

#include "AVLTree.hpp"

#include <iostream>
#include <map>
#include <miniaudio.h>


class Audio {
public:
  Audio();
  ~Audio();

  void setAudio(char s, char* path);
  void play(char s);

  void addAudio(char key, float mvmt);
  void updateList();
  void traverseList(float mvmt);

private:
  ma_engine engine;
  ma_result result;
  std::map<char, ma_sound> sounds;

  AVLTree* tree;

  AVLNode* currentSound;
};

#endif // VOXELOOP_AUDIO_HPP
