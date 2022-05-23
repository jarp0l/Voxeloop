#include "Audio.hpp"

Audio::Audio() {
  result = ma_engine_init(nullptr, &engine);
  if (result != MA_SUCCESS) {
    std::cerr << "Couldn't init engine"
              << std::endl; // Failed to initialize the engine.
    exit(-1);
  }

  std::stringstream aBinding, sBinding, dBinding, fBinding, jBinding, kBinding,
      lBinding, scolonBinding, spaceBinding;
  aBinding << "../core/assets/audio/" << KEY_A_BINDING;
  sBinding << "../core/assets/audio/" << KEY_S_BINDING;
  dBinding << "../core/assets/audio/" << KEY_D_BINDING;
  fBinding << "../core/assets/audio/" << KEY_F_BINDING;
  jBinding << "../core/assets/audio/" << KEY_J_BINDING;
  kBinding << "../core/assets/audio/" << KEY_K_BINDING;
  lBinding << "../core/assets/audio/" << KEY_L_BINDING;
  scolonBinding << "../core/assets/audio/" << KEY_SEMICOLON_BINDING;
  spaceBinding << "../core/assets/audio/" << KEY_SPACE_BINDING;

  // spaceBinding << getBinding(KEY_SPACE_BINDING);

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
  currentSound = nullptr;
}

Audio::~Audio() {
  delete tree;
  ma_engine_uninit(&engine);
}

void Audio::play(char s) {
  ma_sound_seek_to_pcm_frame(&sounds[s], 0);
  ma_sound_start(&sounds[s]);
}

void Audio::setAudio(char s, std::string path) {
  result = ma_sound_init_from_file(&engine, path.c_str(), 0, nullptr, nullptr,
                                   &sounds[s]);

  // char *buf;
  // size_t size;
  // // getcwd(buf, size);
  // std::cout << "[CWD]: " << getcwd(buf, size) << std::endl;

  if (result != MA_SUCCESS) {
    std::cerr << "Couldn't init audio" << std::endl;
    exit(-1);
  }
}

void Audio::addAudio(char key, float mvmt) {
  tree->root = tree->addNode(key, mvmt, tree->root);
  play(key);
}

void Audio::updateList() {
  tree->flatten(tree->root);
  currentSound = tree->root;
}

void Audio::traverseList(float mvmt) {

  if (currentSound == nullptr)
    return;
  if (currentSound->value->mvmt >= mvmt) {
    play(currentSound->value->key);
    currentSound = currentSound->right;
  }

}
