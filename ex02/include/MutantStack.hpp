#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
   public:
	// Constructor / destructor / copy
	MutantStack();
	MutantStack(const MutantStack&);
	MutantStack& operator=(const MutantStack&);
	MutantStack(const Container& container);
	~MutantStack();

	// Iterators
	typedef
	    typename std::stack<T, Container>::container_type::iterator iterator;
	typedef typename std::stack<T, Container>::container_type::const_iterator
	    const_iterator;
	typedef typename std::stack<T, Container>::container_type::reverse_iterator
	    reverse_iterator;
	typedef
	    typename std::stack<T,
		                    Container>::container_type::const_reverse_iterator
	        const_reverse_iterator;

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	reverse_iterator rbegin();
	reverse_iterator rend();

	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif
