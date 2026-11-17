#include "MonsterStack.hpp"
#include "MonsterStack.tpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

#define SIZE 20000

int main() {
  std::stack<int> test;
  for (int i = 0; i < 50; ++i)
    test.push(i);

  MonsterStack<int> abc(test);
}
