#include "CoreEngine.hpp"
#include "StateMachine.hpp"

void CoreEngine::init(const char *title, int width, int height, int bpp,
                      bool fullscreen) {
  m_fullscreen = fullscreen;
  m_isRunning = true;

  m_gameData->window.create(title, width, height);

  m_window = m_gameData->window.getWindow();
  m_gameData->gui.init(m_window);

  std::cout << "[INFO] CoreEngine initialized\n\n<<< Here we go >>>\n\n";
}

void CoreEngine::cleanup() {
  // cleanup the all states
  while (!states.empty()) {
    states.back()->cleanup();
    states.pop_back();
  }

  std::cout << "\n<<< Good bye! >>>\n\n[INFO] CoreEngine cleaned\n";

  m_gameData->gui.cleanup();
  m_gameData->window.cleanup();
}

void CoreEngine::changeState(StateMachine *state) {
  // cleanup the current state
  if (!states.empty()) {
    states.back()->cleanup();
    states.pop_back();
  }

  // store and init the new state
  states.push_back(state);
  states.back()->init();
}

void CoreEngine::pushState(StateMachine *state) {
  // pause current state
  if (!states.empty()) {
    states.back()->pause();
  }

  // store and init the new state
  states.push_back(state);
  states.back()->init();
}

void CoreEngine::popState() {
  // cleanup the current state
  if (!states.empty()) {
    states.back()->cleanup();
    states.pop_back();
  }

  // resume previous state
  if (!states.empty()) {
    states.back()->resume();
  }
}

void CoreEngine::handleEvents() {
  // let the state handle events
  states.back()->handleEvents(this);
}

void CoreEngine::update() {
  // let the state update the engine
  states.back()->update(this);
}

void CoreEngine::draw() {
  // let the state draw the screen
  if (m_gameData->window.isCloseRequested())
    this->quit();
  else
    states.back()->draw(this);
}
