#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <complex>
#include <iostream>

Span::Span() : _max_size(0) {}

Span::Span(const unsigned int n) : _max_size(n) { _content.reserve(n); }

Span::Span(const Span &other)
    : _max_size(other._max_size), _content(other._content) {
  _content.reserve(other._max_size);
}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    _max_size = other._max_size;
    _content = other._content;
    _content.reserve(_max_size);
  }
  return *this;
}

void Span::addNumber(const int nb) {
  if (_content.size() + 1 >= _content.capacity())
    throw overflow();
  _content.push_back(nb);
}

void Span::fill_rand() {
  _content.resize(_max_size);
  std::generate(_content.begin(), _content.end(), std::rand);
}

const int &Span::operator[](const unsigned int at) const {
  if (at >= _content.size())
    throw overflow();
  return _content[at];
}

unsigned int Span::longestSpan() const {
  if (_content.size() <= 1)
    throw impossible_span();
  Span sorter(*this);
  std::sort(sorter._content.begin(), sorter._content.end());
  return sorter._content.back() - sorter[0];
}

unsigned int Span::shortestSpan() const {
  if (_content.size() <= 1)
    throw impossible_span();
  unsigned long shortest = ULONG_MAX;
  Span sorter(*this);
  std::sort(sorter._content.begin(), sorter._content.end());
  for (std::size_t i = 0; i < _content.size() - 1; ++i) {
    if (sorter[i + 1] - sorter[i] < shortest)
      shortest = sorter[i + 1] - sorter[i];
  }

  return shortest;
}

Span::~Span() {}