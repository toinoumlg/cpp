#ifndef ARRAY_HPP
#define ARRAY_HPP

#define MAX_VAL 1555510

#include <cstdlib>
#include <iostream>
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

	size_t size() const;

   private:
	size_t _size;
	T* _value;
};

template <typename T>
Array<T>::Array() : _size(0), _value(NULL) {}

template <typename T>
Array<T>::Array(const unsigned int size)
    : _size(size), _value(new T[_size]()) {}

template <typename T>
Array<T>::Array(const Array& other)
    : _size(other._size), _value(new T[_size]()) {
	for (size_t i = 0; i < _size; ++i) {
		_value[i] = other[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this == &other)
		return *this;
	delete[] _value;
	_value = new T[other._size]();
	_size = other._size;
	for (size_t i = 0; i < _size; ++i)
		_value[i] = other[i];
	return *this;
}

template <typename T>
T& Array<T>::operator[](int at) {
	if (at < 0 || static_cast<size_t>(at) >= _size)
		throw std::exception();
	return _value[at];
}

template <typename T>
T Array<T>::operator[](int at) const {
	if (at < 0 || static_cast<size_t>(at) >= _size)
		throw std::exception();
	return _value[at];
}

template <typename T>
Array<T>::~Array() {
	delete[] _value;
}

template <typename T>
size_t Array<T>::size() const {
	return _size;
}

#endif
