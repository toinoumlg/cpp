#include "easyfind.hpp"

#include <deque>
#include <iostream>
#include <set>
#include <vector>

#define SIZE 200

int main() {
  std::vector<int> vec;
  std::set<int> set;
  std::deque<int> deque;

  for (int i = 0; i < SIZE; ++i) {
    vec.push_back(i);
    set.insert(set.begin(), i);
    deque.push_front(i * i);
  }
  const std::set<int> const_set = set;

  try_catch(deque, 30);
  try_catch(deque, 1);
  try_catch(deque, 1);
  try_catch(deque, 1);
  try_catch(deque, 1);
  try_catch(deque, 1);
  try_catch(deque, 1);
  try_catch(deque, 1);
  easyfind(vec, 5);
}
