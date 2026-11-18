#ifndef MONSTER_STACK_TPP
#define MONSTER_STACK_TPP
#include "MutantStack.hpp"

template <typename T> MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other) {
  if (this != &other) {
    std::stack<T>::operator=(other);
  }
  return *this;
}

template <class T>
MutantStack<T>::MutantStack(const std::stack<T> &other)
    : std::stack<T>(other) {}

template <typename T> MutantStack<T>::~MutantStack() {}

template <typename T>
template <typename Container>
MutantStack<T>::MutantStack(const Container &container) : std::stack<T>() {
  for (typename Container::const_iterator it = container.begin();
       it != container.end(); ++it)
    this->push(*it);
}

template <class T> typename MutantStack<T>::iterator MutantStack<T>::begin() {
  return std::stack<T>::c.begin();
}

template <class T> typename MutantStack<T>::iterator MutantStack<T>::end() {
  return std::stack<T>::c.end();
}

template <class T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
  return std::stack<T>::c.begin();
}

template <class T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
  return std::stack<T>::c.end();
}

template <class T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
  return std::stack<T>::c.rbegin();
}

template <class T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
  return std::stack<T>::c.rend();
}

template <class T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
  return std::stack<T>::c.rbegin();
}

template <class T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {
  return std::stack<T>::c.rend();
}

#endif
