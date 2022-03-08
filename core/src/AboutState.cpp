#include "AboutState.hpp"

AboutState AboutState::m_AboutState;

void AboutState::init() { std::cout << "[INFO] AboutState initialized\n"; }

void AboutState::cleanup() { std::cout << "[INFO] AboutState cleaned\n"; }

void AboutState::pause() { std::cout << "[INFO] AboutState paused\n"; }

void AboutState::resume() { std::cout << "[INFO] AboutState resumed\n"; }

void AboutState::handleEvents(CoreEngine *engine) {}

void AboutState::update(CoreEngine *engine) {}

void AboutState::draw(CoreEngine *engine) {

  m_sharedData->gui.begin();

  if (m_sharedData->gui.renderAbout(&m_sharedData->window))
    engine->popState();

  m_sharedData->gui.end();
}
