#include "Span.hpp"

#include <algorithm>
#include <cstdlib>

Span::Span() : _max_size(0) {}

Span::Span(const unsigned int n) : _max_size(n) { _content.reserve(n); }

Span::Span(const Span &other)
    : _content(other._content), _max_size(other._max_size) {
  _content.reserve(other._max_size);
}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    _content = other._content;
    _max_size = other._max_size;
    _content.reserve(other._max_size);
  }
  return *this;
}

void Span::addNumber(const int nb) {
  if (_content.size() >= _max_size)
    throw overflow();
  _content.push_back(nb);
}

void Span::fill_rand() {
  std::generate_n(std::back_inserter(_content), _max_size - _content.size(),
                  std::rand);
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
  return static_cast<unsigned int>(max) - static_cast<unsigned int>(min);
}

unsigned int Span::shortestSpan() const {
  if (_content.size() <= 1)
    throw impossible_span();
  std::vector<int> sorted(_content);
  std::sort(sorted.begin(), sorted.end());
  unsigned long shortest = static_cast<unsigned int>(sorted[1]) -
                           static_cast<unsigned int>(sorted[0]);
  for (std::size_t i = 0; i < sorted.size() - 1; ++i) {
    unsigned int diff = static_cast<unsigned int>(sorted[i + 1]) -
                        static_cast<unsigned int>(sorted[i]);
    if (diff < shortest)
      shortest = diff;
    if (shortest == 0)
      break;
  }

  return shortest;
}

Span::~Span() {}