#pragma once
#include <vector>

class overflow : std::exception {
public:
  const char *what() const throw() {
    return "trying to add number when Span is full";
  }
};

class invalid_range : std::exception {
public:
  const char *what() const throw() { return "invalid range access on Span"; }
};

class impossible_span : std::exception {
public:
  const char *what() const throw() { return "impossible span request"; }
};

class Span {
public:
  Span();
  Span(unsigned int n);
  Span(const Span &other);
  Span &operator=(const Span &other);
  void addNumber(int nb);
  template <typename Iterator> void addRange(Iterator begin, Iterator end);
  void fill_rand();
  ~Span();

  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;

  const int &operator[](unsigned int) const;

private:
  std::vector<int> _content;
};

template <typename Iterator> void Span::addRange(Iterator begin, Iterator end) {
  if (_content.size() + std::distance(begin, end) > _content.capacity())
    throw invalid_range();
  _content.insert(_content.end(), begin, end);
}
