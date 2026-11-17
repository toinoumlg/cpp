#pragma once
#include <stack>
#include <vector>

template <class T> class MonsterStack {
public:
  // Constructor / destructor / copy
  MonsterStack();
  MonsterStack(const MonsterStack &);
  MonsterStack &operator=(const MonsterStack &);
  template <typename C> MonsterStack(const C &);
  ~MonsterStack();

  // Accessor
  T top() const;

  // Capacity
  bool empty() const;
  std::size_t size() const;

  // Modifiers
  void push(const T &);
  void pop();

  // Iterators

private:
  std::stack<T> _stack;
};
