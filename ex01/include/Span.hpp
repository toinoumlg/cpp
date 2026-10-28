#pragma once
#include <vector>

class overflow : std::exception {
  const char *what() const throw() {
    return "trying to add number when Span is full";
  }
};

class invalid_range : std::exception {
  const char *what() const throw() { return "invalid range on Span"; }
};

class impossible_span : std::exception {
  const char *what() const throw() { return "impossible span request"; }
};

class Span {
public:
  Span();
  Span(unsigned int n);
  Span(const Span &other);
  Span &operator=(const Span &other);
  void addNumber(int nb);
  void addRange(unsigned int begin, unsigned int end);
  void fill();
  ~Span();

  unsigned int shortestSpan();
  unsigned int longestSpan();

  int operator[](unsigned int) const;

private:
  std::vector<int> _content;
};
