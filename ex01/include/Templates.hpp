#pragma once

#include <functional>

template <typename T>
void iter(T *ptr, unsigned int lenght, std::function<void(T)> f) {
	for (int i = 0; i < lenght; i++)
		f(ptr[i]);
}