#include "TemplateState.hpp"

TemplateState TemplateState::m_TemplateState;

void TemplateState::init() {
  std::cout << "[INFO] TemplateState initialized\n";
}

void TemplateState::cleanup() { std::cout << "[INFO] TemplateState cleaned\n"; }

void TemplateState::pause() { std::cout << "[INFO] TemplateState paused\n"; }

void TemplateState::resume() { std::cout << "[INFO] TemplateState resumed\n"; }

void TemplateState::handleEvents(CoreEngine *engine) {}

void TemplateState::update(CoreEngine *engine) {}

void TemplateState::draw(CoreEngine *engine) {
  m_sharedData->window.update();
  m_sharedData->window.clear();

  // draw all the stuffs here

  // m_sharedData->gui.getFrame();
  // m_sharedData->gui.renderMenu(&m_sharedData->window);

  m_sharedData->window.render();
}
