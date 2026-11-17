#include "Span.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#define SIZE 20000

int main() {
  srand(time(NULL));
  Span s(SIZE);
  Span other(SIZE);
  std::vector<int> v;
  v.reserve(SIZE * 2);
  for (int i = 0; i < SIZE * 2; ++i)
    v.push_back(i);
  s.fill_rand();
  other.addRange(v.begin(), v.end() - SIZE);

  // other.addRange(100, 20000);

  std::cout << other.longestSpan() << std::endl;
  std::cout << other.shortestSpan() << std::endl;
  std::cout << s.shortestSpan() << std::endl;
  for (int i = 0; i < SIZE; ++i)
    std::cout << other[i] << std::endl;

  for (int i = 0; i < SIZE; ++i)
    std::cout << s[i] << std::endl;
}
