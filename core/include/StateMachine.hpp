#ifndef CORE_INCLUDE_STATEMACHINE_HPP
#define CORE_INCLUDE_STATEMACHINE_HPP

#include "State.hpp"
#include <memory>
#include <stack>

///
/// @brief A unique pointer for storing the states
///
/// All the states are inherited from the abstract class `State` that makes it
/// possible to use the same pointer for all the states
///
typedef std::unique_ptr<State> StateRef;

///
/// @brief Class for managing the states in the project
///
class StateMachine {
public:
  ///
  /// @brief Construct a new State Machine object
  ///
  StateMachine() {}

  ///
  /// @brief Add a new state to the state machine
  ///
  /// @param newState The unique pointer to the new state
  /// @param isReplaced Whether the state at the top of the stack is being
  /// replaced or another state is being pushed at the top of it
  ///
  void addState(StateRef newState, bool isReplaced = true);

  ///
  /// @brief Remove the state at the top of the stack
  ///
  void removeState();

  ///
  /// @brief Process the changes in the state
  ///
  void processStateChanges();

  ///
  /// @brief Get the Active State object, i.e the state at the top of the stack
  ///
  /// @return StateRef& The reference to the state at the top of the stack
  StateRef &getActiveState();

  ///
  /// @brief Destroy the State Machine object
  ///
  ~StateMachine() {}

private:
  std::stack<StateRef> _states; /// Stack to store states
  StateRef _newState; /// The unique pointer to new state that is being added
  bool _isAdded;      /// Whether a new state is being added
  bool _isReplaced;   /// Whether the state at the top of stack is being
                      /// popped or another state is being pushed
  bool _isRemoved;    /// Whether the state at the top of stack is being popped
};

#endif // CORE_INCLUDE_STATEMACHINE_HPP
