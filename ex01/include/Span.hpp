#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iterator>
#include <vector>

class overflow : public std::exception {
   public:
	const char* what() const throw() {
		return "trying to add number when Span is full";
	}
};

class invalid_range : public std::exception {
   public:
	const char* what() const throw() { return "invalid range access on Span"; }
};

class impossible_span : public std::exception {
   public:
	const char* what() const throw() { return "impossible span request"; }
};

class Span {
   public:
	Span();
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	void addNumber(int nb);
	template <typename Iterator>
	void addRange(Iterator begin, Iterator end);
	void fill_rand();
	~Span();

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	const int& operator[](unsigned int) const;

   private:
	std::vector<int> _content;
	unsigned int _max_size;
};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
	const long dist = std::distance(begin, end);
	if (dist < 0)
		throw invalid_range();
	if (static_cast<std::size_t>(dist) > _max_size - this->_content.size())
		throw overflow();
	_content.insert(_content.end(), begin, end);
}

#endif
