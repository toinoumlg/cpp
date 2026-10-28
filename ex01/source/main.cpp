#include "Span.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#define SIZE 20000

int main() {
  srand(time(NULL));
  Span s(SIZE);
  Span other(SIZE);
  return 0;
  s.fill();
  other.addRange(0, 100);

  other.addRange(100, 20000);

  for (int i = 0; i < SIZE; ++i)
    std::cout << other[i] << std::endl;

  for (int i = 0; i < SIZE; ++i)
    std::cout << s[i] << std::endl;
}
