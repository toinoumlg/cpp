#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T* ptr, const unsigned int length, F f) {
	for (unsigned int i = 0; i < length; i++)
		f(ptr[i]);
}

template <typename T>
void print(const T& x) {
	std::cout << x << std::endl;
}

template <typename T>
void add(T& x) {
	++x;
}

template <>
void add(std::string& x) {
	iter(&x[0], x.size(), add<char>);
}

#endif
