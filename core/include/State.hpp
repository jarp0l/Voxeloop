#ifndef CORE_INCLUDE_STATE_HPP
#define CORE_INCLUDE_STATE_HPP

class State {
public:
  ///
  /// @brief Initialize state related data
  ///
  virtual void init() = 0;

  ///
  /// @brief Draw state objects
  ///
  virtual void draw() = 0;

  ///
  /// @brief Update state data
  ///
  virtual void update() = 0;

  ///
  /// @brief Handle user input
  ///
  // virtual void handleInput() = 0;

  ///
  /// @brief Pause a state
  ///
  virtual void pause();

  ///
  /// @brief Resume paused state
  ///
  virtual void resume();

  ///
  /// @brief Destroy the State object
  ///
  virtual ~State() = default;
  // virtual ~State() {}
};

#endif // CORE_INCLUDE_STATE_HPP
