#include "../include/IntroState.hpp"
// #include "ImguiWrapper.hpp"

IntroState::IntroState(GameDataRef gameData) : m_gameData{gameData} {}

void IntroState::init() {
  // m_imgui.init();
  // m_gameData->gui.newFrame();
  m_gui.init(m_gameData->window.getWindow());
}

void IntroState::update() {
  // m_gameData->window.update();
}

void IntroState::draw() {
  m_gameData->window.clear();

  // draw actual stuffs here
  m_gui.getFrame();

  // Render GUI
  m_gui.renderGUI();

  m_gameData->window.render();
  m_gameData->window.update();
}

// void IntroState::handleInput() {}
