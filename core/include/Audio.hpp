#ifndef VOXELOOP_AUDIO_HPP
#define VOXELOOP_AUDIO_HPP

#include <miniaudio.h>

#include <iostream>
#include <map>

class Audio {
public:
  Audio();
  ~Audio();

  void setAudio(char s, char* path);
  void play(char s);
private:
  ma_engine engine;
  ma_result result;
  std::map<char, ma_sound> sounds;
};

#endif // VOXELOOP_AUDIO_HPP
