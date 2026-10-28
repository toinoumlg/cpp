#include "Span.hpp"
#include <algorithm>
#include <complex>
#include <iostream>

Span::Span() {}

Span::Span(unsigned int n) { _content.reserve(n); }

Span::Span(const Span &other) : _content(other._content) {}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    _content = other._content;
  }
  return *this;
}

void Span::addNumber(const int nb) {
  if (_content.size() + 1 >= _content.capacity())
    throw overflow();
  _content.push_back(nb);
}

void Span::addRange(const unsigned int begin, const unsigned int end) {
  if (end <= begin || end - begin > _content.capacity())
    throw invalid_range();
  _content.insert(_content.begin() + begin, end - begin, 0);
  std::generate_n(_content.begin() + begin, end - begin, rand);
}

int rand() { return std::(); }

void Span::fill() {
  _content.insert(_content.begin(), _content.capacity(), 0);
  std::generate_n(_content.begin(), _content.capacity(), rand);
}

int Span::operator[](const unsigned int at) const {
  if (at >= _content.size())
    throw overflow();
  return _content[at];
}

unsigned int Span::longestSpan() {
  if (_content.size() <= 1)
    throw impossible_span();
  unsigned int longest = 0;
  for (std::vector<int>::const_iterator first = _content.begin();
       first != _content.end(); ++first)
    for (std::vector<int>::const_iterator second = _content.begin();
         second != _content.end(); ++second) {
      if (first == second)
        continue;
    }
  return 0;
}

unsigned int Span::shortestSpan() { return 0; }

Span::~Span() {}