#include "StateMachine.hpp"

void StateMachine::addState(StateRef newState, bool isReplaced) {
  this->_isAdded = true;
  this->_isReplaced = isReplaced;
  this->_newState = std::move(newState);
}

void StateMachine::removeState() { this->_isRemoved = true; }

void StateMachine::processStateChanges() {
  if (_isRemoved && !_states.empty()) {
    this->_states.pop();

    if (!_states.empty())
      this->_states.top()->resume();

    this->_isRemoved = false;
  }

  if (_isAdded) {
    if (_isReplaced && !_states.empty())
      this->_states.pop();

    else if (!_states.empty())
      this->_states.top()->pause();

    this->_states.push(std::move(this->_newState));
    this->_states.top()->init();
    this->_isAdded = false;
  }
}

StateRef &StateMachine::getActiveState() { return this->_states.top(); }
