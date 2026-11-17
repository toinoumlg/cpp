#ifndef MONSTER_STACK_TPP
#define MONSTER_STACK_TPP
#include "MonsterStack.hpp"

template <typename T> MonsterStack<T>::MonsterStack() {}

template <typename T>
MonsterStack<T>::MonsterStack(const MonsterStack &other)
    : _stack(other._stack) {}

template <typename T>
MonsterStack<T> &MonsterStack<T>::operator=(const MonsterStack &other) {
  if (this != &other) {
    _stack = other._stack;
  }
  return *this;
}

template <typename T> MonsterStack<T>::~MonsterStack() {}

template <typename T>
template <typename C>
MonsterStack<T>::MonsterStack(const C &container) {
  _stack = container;
}

template <typename T> T MonsterStack<T>::top() const { return _stack.top(); }

template <typename T> bool MonsterStack<T>::empty() const {
  return _stack.empty();
}

template <typename T> std::size_t MonsterStack<T>::size() const {
  return _stack.size();
}

template <typename T> void MonsterStack<T>::push(const T &value) {
  _stack.push(value);
}

template <typename T> void MonsterStack<T>::pop() { _stack.pop(); }

#endif
