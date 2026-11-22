#include <limits.h>

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Span.hpp"

#define SIZE 20000

static void subject() {
	std::cout << "Subject" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

static void overflow() {
	std::cout << "Overflow" << std::endl;
	Span sp(1);
	sp.addNumber(58);
	try {
		sp.addNumber(59);
	} catch (const class overflow& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void empty() {
	std::cout << "Empty" << std::endl;
	Span empty(0);
	Span single(1);
	single.addNumber(10);
	try {
		std::cout << empty.longestSpan() << std::endl;
	} catch (const impossible_span& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::cout << single.longestSpan() << std::endl;
	} catch (const impossible_span& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void max() {
	std::cout << "Max" << std::endl;
	Span sp(2);
	sp.addNumber(INT_MIN);
	sp.addNumber(INT_MAX);
	std::cout << "shortest :" << sp.shortestSpan() << std::endl;
	std::cout << "longest :" << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

static void dup() {
	std::cout << "Dup and copy" << std::endl;
	Span dup(6);
	dup.addNumber(-20);
	dup.addNumber(50);
	dup.addNumber(300);
	dup.addNumber(-150);
	dup.addNumber(-20);
	dup.addNumber(10);
	std::cout << "longest: " << dup.longestSpan() << std::endl;
	std::cout << "shortest: " << dup.shortestSpan() << std::endl;

	Span copy(dup);
	Span _operator;
	_operator = copy;
	std::cout << "copy: " << copy.longestSpan() << std::endl;
	std::cout << "operator: " << _operator.longestSpan() << std::endl;
	std::cout << std::endl;
	std::vector<int> v;
	for (int i = 0; i < 100; ++i)
		v.push_back(i);

	try {
		dup.addRange(v.begin(), v.end());
	} catch (const class overflow& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	try {
		dup.addRange(v.end(), v.begin());
	} catch (const invalid_range& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

static void range() {
	std::cout << "Range" << std::endl;
	Span sp(SIZE);
	std::vector<int> v;
	v.reserve(SIZE);
	for (int i = 0; i < SIZE; ++i)
		v.push_back(i);
	sp.addRange(v.begin(), v.end());
	std::cout << sp.longestSpan() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << std::endl;
}

static void random_span() {
	std::cout << "Random" << std::endl;
	srand(time(NULL));
	Span sp(SIZE);
	sp.fill_rand();

	std::cout << sp.longestSpan() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;

	std::cout << sp[500] << std::endl;

	try {
		std::cout << sp[SIZE] << std::endl;
	} catch (const invalid_range& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	subject();
	overflow();
	empty();
	max();
	dup();
	range();
	random_span();
}
