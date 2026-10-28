#pragma once

template <typename T>
void func(T param) {}

template <typename T>
void iter(T *ptr, unsigned int length, func(T)) {
	for (int i = 0; i < length; i++)
		f(ptr[i]);
}