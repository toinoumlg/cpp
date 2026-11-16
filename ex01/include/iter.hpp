#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T* ptr, const std::size_t length, F f) {
	if (!ptr)
		return;
	for (std::size_t i = 0; i < length; i++)
		f(ptr[i]);
}

#endif
