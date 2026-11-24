#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <cstdlib>
#include <iostream>
#include <vector>

template <class C = std::vector<unsigned int> >
class PmergeMe {
   public:
	PmergeMe();
	PmergeMe(const PmergeMe&);
	PmergeMe& operator=(const PmergeMe&);
	~PmergeMe();

	PmergeMe(char** args);

	void Merge();

   private:
	C _data;
};

template <class C>
PmergeMe<C>::PmergeMe() {}

template <class C>
PmergeMe<C>::PmergeMe(const PmergeMe& other) : _data(other._data) {}

template <class C>
PmergeMe<C>& PmergeMe<C>::operator=(const PmergeMe& other) {
	if (this != &other)
		_data = other._data;
	return *this;
}

template <class C>
PmergeMe<C>::PmergeMe(char** args) {
	std::cout << "Before:";

	while (*args) {
		char* end = NULL;
		unsigned long value = std::strtoul(*args, &end, 10);
		if (!**args || *end != '\0')
			throw std::exception();
		_data.push_back(value);
		std::cout << " " << value;
		args++;
	}
	std::cout << std::endl;
}
template <class C>
void PmergeMe<C>::Merge() {}

template <class C>
PmergeMe<C>::~PmergeMe() {}

#endif
