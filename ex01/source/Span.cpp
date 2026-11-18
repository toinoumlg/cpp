#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <complex>
#include <iostream>

Span::Span() { _content.reserve(0); }

Span::Span(const unsigned int n) { _content.reserve(n); }

Span::Span(const Span &other) : _content(other._content) {
  _content.reserve(other._content.capacity());
}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    _content = other._content;
    _content.reserve(other._content.capacity());
  }
  return *this;
}

void Span::addNumber(const int nb) {
  if (_content.size() >= _content.capacity())
    throw overflow();
  _content.push_back(nb);
}

void Span::fill_rand() {
  _content.resize(_content.capacity());
  std::generate(_content.begin(), _content.end(), std::rand);
}

const int &Span::operator[](const unsigned int at) const {
  if (at >= _content.size())
    throw invalid_range();
  return _content[at];
}

unsigned int Span::longestSpan() const {
  if (_content.size() <= 1)
    throw impossible_span();
  const int min = *std::min_element(_content.begin(), _content.end());
  const int max = *std::max_element(_content.begin(), _content.end());
  return max - min;
}

unsigned int Span::shortestSpan() const {
  if (_content.size() <= 1)
    throw impossible_span();
  unsigned long shortest = ULONG_MAX;
  std::vector<int> finder(_content);
  std::sort(finder.begin(), finder.end());
  for (std::size_t i = 0; i < finder.size() - 1; ++i) {
    if (static_cast<unsigned long>(finder[i + 1] - finder[i]) < shortest)
      shortest = finder[i + 1] - finder[i];
  }

  return shortest;
}

Span::~Span() {}