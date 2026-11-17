#include "Span.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#define SIZE 20000

int main() {
  srand(time(NULL));
  Span t(1);
  t.addNumber(58);
  Span s(SIZE);

  Span test(3);
  Span other(SIZE);
  std::vector<int> v;
  v.reserve(SIZE * 2);
  for (int i = 0; i < SIZE * 2; ++i)
    v.push_back(i);
  s.fill_rand();
  other.addRange(v.begin(), v.end() - SIZE);

  try {
    unsigned int _ = t.longestSpan();
  } catch (impossible_span &e) {
    std::cout << "error :" << e.what() << std::endl;
  }
  test.addNumber(-20);
  test.addNumber(-3);
  test.addNumber(40);

  std::cout << test.shortestSpan() << std::endl;
  std::cout << test.longestSpan() << std::endl;

  std::cout << other.longestSpan() << std::endl;
  std::cout << other.shortestSpan() << std::endl;
  std::cout << s.shortestSpan() << std::endl;

  return 0;
  for (int i = 0; i < SIZE; ++i)
    std::cout << other[i] << std::endl;

  for (int i = 0; i < SIZE; ++i)
    std::cout << s[i] << std::endl;
}
