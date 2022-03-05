#include "Audio.hpp"
#include "../audio/Bindings.hpp"
#include <sstream>

Audio::Audio() {
  result = ma_engine_init(nullptr, &engine);
  if (result != MA_SUCCESS) {
    std::cerr << result << std::endl; // Failed to initialize the engine.
  }

  std::stringstream aBinding, sBinding, dBinding, fBinding, jBinding, kBinding, lBinding, scolonBinding, spaceBinding;
  aBinding << "../core/audio/" << KEY_A_BINDING;
  sBinding << "../core/audio/" << KEY_S_BINDING;
  dBinding << "../core/audio/" << KEY_D_BINDING;
  fBinding << "../core/audio/" << KEY_F_BINDING;
  jBinding << "../core/audio/" << KEY_J_BINDING;
  kBinding << "../core/audio/" << KEY_K_BINDING;
  lBinding << "../core/audio/" << KEY_L_BINDING;
  scolonBinding << "../core/audio/" << KEY_SEMICOLON_BINDING;
  spaceBinding << "../core/audio/" << KEY_SPACE_BINDING;

  setAudio('a', aBinding.str());
  setAudio('s', sBinding.str());
  setAudio('d', dBinding.str());
  setAudio('f', fBinding.str());
  setAudio('j', jBinding.str());
  setAudio('k', kBinding.str());
  setAudio('l', lBinding.str());
  setAudio(';', scolonBinding.str());
  setAudio(' ', spaceBinding.str());
  tree = new Tree;
}

Audio::~Audio() {
  delete tree;
}

void Audio::play(char s) {
  ma_sound_seek_to_pcm_frame(&sounds[s], 0);
  ma_sound_start(&sounds[s]);
}

void Audio::setAudio(char s, std::string path) {
  result = ma_sound_init_from_file(&engine, path.c_str(), 0, nullptr, nullptr, &sounds[s]);
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
