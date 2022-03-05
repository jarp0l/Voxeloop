#include "Audio.hpp"

Audio::Audio() {
  result = ma_engine_init(nullptr, &engine);
  if (result != MA_SUCCESS) {
    std::cerr <<  result << std::endl;  // Failed to initialize the engine.
  }

  setAudio('a', "../core/audio/b.wav");
  setAudio('s', "../core/audio/drum.wav");
  setAudio('d', "../core/audio/drum.wav");
  setAudio('f', "../core/audio/drum.wav");
  setAudio('j', "../core/audio/drum.wav");
  setAudio('k', "../core/audio/drum.wav");
  setAudio('l', "../core/audio/drum.wav");
  setAudio(';', "../core/audio/drum.wav");
  setAudio(' ', "../core/audio/b.wav");
//  setAudio(' ', "../core/audio/lmmssamples/effects/scratch01.ogg");
  tree = new AVLTree;
}

Audio::~Audio() {
  delete tree;
}

void Audio::play(char s) {
  ma_sound_seek_to_pcm_frame(&sounds[s], 0);
  ma_sound_start(&sounds[s]);
}

void Audio::setAudio(char s, char *path) {
  result = ma_sound_init_from_file(&engine, path, 0, nullptr, nullptr, &sounds[s]);
  if (result != MA_SUCCESS) {
    std::cerr << "Couldn't init audio" << std::endl;
  }
}

void Audio::addAudio(char key, float mvmt) {
  play(key);
  tree->root = tree->addNode(key, mvmt, tree->root);
}

void Audio::updateList() {
  tree->flatten(tree->root);
  currentSound = tree->root;
}

void Audio::traverseList(float mvmt) {
  if (currentSound == nullptr) return;
  if(currentSound->value->mvmt >= mvmt) {
    play(currentSound->value->key);
    currentSound = currentSound->right;
  }
}
