#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <class T, class Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}

template <class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other)
    : std::stack<T, Container>(other) {}

template <class T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(
    const MutantStack& other) {
	if (this != &other) {
		std::stack<T, Container>::operator=(other);
	}
	return *this;
}
template <class T, class Container>
MutantStack<T, Container>::MutantStack(const Container& container)
    : std::stack<T, Container>(container) {}

template <class T, class Container>
MutantStack<T, Container>::~MutantStack() {}

template <class T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin() {
	return std::stack<T, Container>::c.begin();
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
	return std::stack<T, Container>::c.end();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::begin() const {
	return std::stack<T, Container>::c.begin();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::end() const {
	return std::stack<T, Container>::c.end();
}
template <class T, class Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rbegin() {
	return std::stack<T, Container>::c.rbegin();
}

template <class T, class Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rend() {
	return std::stack<T, Container>::c.rend();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::rbegin() const {
	return std::stack<T, Container>::c.rbegin();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::rend() const {
	return std::stack<T, Container>::c.rend();
}

#endif
