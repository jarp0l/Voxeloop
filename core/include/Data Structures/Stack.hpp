#ifndef CORE_INCLUDE_STACK_HPP
#define CORE_INCLUDE_STACK_HPP

#include "Error.hpp"

#include <climits>
#include <deque>
#include <iostream>

const auto MAX_SIZE = 100;

///
/// @brief A data structure that works in LIFO principle
///
/// @tparam T Type of element
template <class T, class Container = std::deque<T>> class Stack {
  size_t _top;
  T stack[MAX_SIZE];

public:
  // initialization
  Stack() { _top = -1; }

  bool isEmpty() {
    // check if the stack is empty
    return (_top == -1);
  }

  bool isFull() {
    // check if the stack is full
    return (_top >= MAX_SIZE - 1);
  }

  T push(T element) {
    if (isFull()) {
      throw EmptyError();
      // std::cerr << "Stack overflow! No more elements can be pushed." <<
      // std::endl; exit(EXIT_FAILURE);
    }

    stack[++_top] = element;
    return element;
  }

  T pop() {
    if (isEmpty()) {
      throw EmptyError();
      // std::cerr << "Stack underflow! No element to pop." << std::endl;
      // exit(EXIT_FAILURE);
    }

    T itemPopped = stack[_top--];
    return itemPopped;
  }

  void peek() {
    // peek at the _top of the stack
    if (isEmpty()) {
      throw EmptyError();
      // std::cerr << "No element in stack." << std::endl;
      // exit(EXIT_FAILURE);
    }

    std::cout << stack[_top] << std::endl;
  }

  T top() {
    // peek at the top of the stack
    if (isEmpty()) {
      std::cerr << "No element in stack." << std::endl;
      exit(EXIT_FAILURE);
    }

    return stack[_top];
  }
};

#endif // CORE_INCLUDE_STACK_HPP
