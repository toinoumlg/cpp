#pragma once

#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array {
   public:
	Array();
	Array(unsigned int);
	Array(const Array&);
	~Array();

	Array& operator=(const Array&);

	T& operator[](int);
	T operator[](int) const;

   private:
	size_t _size;
	T* _value;
};

template <typename T>
Array<T>::Array() : _size(0), _value(NULL) {}

template <typename T>
Array<T>::Array(const unsigned int size) : _size(size), _value(new T[_size]) {}

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size), _value(new T[_size]) {
	for (size_t i = 0; i < _size; ++i) {
		_value[i] = other[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this == &other)
		return *this;
	return *this = Array(other);
}

template <typename T>
T& Array<T>::operator[](int at) {
	if (at < 0 || static_cast<size_t>(at) >= _size)
		throw std::range_error("range error on Array");
	return _value[at];
}

template <typename T>
T Array<T>::operator[](int at) const {
	if (at < 0 || static_cast<size_t>(at) >= _size)
		throw std::range_error("range error on Array");
	return _value[at];
}

template <typename T>
Array<T>::~Array() {
	delete[] _value;
}
