#pragma once
#include <algorithm>
#include <iostream>

class not_found : std::exception {
public:
  const char *what() const throw() { return "not_found"; }
};

template <typename C> typename C::iterator easyfind(C &container, int value) {
  typename C::iterator it =
      std::find(container.begin(), container.end(), value);
  if (it == container.end())
    throw not_found();
  return it;
}

template <typename C>
typename C::const_iterator easyfind(const C &container, int value) {
  typename C::const_iterator it =
      std::find(container.begin(), container.end(), value);
  if (it == container.end())
    throw not_found();
  return it;
}

template <typename C> void try_catch(const C &container, int value) {
  try {
    easyfind(container, value);
  } catch (not_found &e) {
    std::cout << e.what() << std::endl;
  }
}

template <typename C> void try_catch(C &container, int value) {
  try {
    easyfind(container, value);
  } catch (not_found &e) {
    std::cout << e.what() << std::endl;
  }
}

