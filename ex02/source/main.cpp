#include <iostream>
#include <list>
#include <vector>

#include "MutantStack.hpp"

#define SIZE 20000

static void subject() {
	std::cout << "Subject" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "mstack size = " << mstack.size() << " top = " << mstack.top()
	          << std::endl;

	std::cout << "copy size = " << s.size() << " top = " << s.top()
	          << std::endl;
	std::cout << std::endl;
}

static void list() {
	std::cout << "List comparison, Copy Operator and Constructor :"
	          << std::endl;
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator it_end = list.end();
	while (it != it_end) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int, std::list<int> > copy(list);
	MutantStack<int, std::list<int> > mstack(list);
	MutantStack<int, std::list<int> > _operator;
	_operator = mstack;
	std::cout << "list size = " << list.size() << " top = " << list.back()
	          << std::endl;

	std::cout << "mstack size = " << mstack.size() << " top = " << mstack.top()
	          << std::endl;

	std::cout << "copy size = " << copy.size() << " top = " << copy.top()
	          << std::endl;

	std::cout << "operator size = " << _operator.size()
	          << " top = " << _operator.top() << std::endl;

	std::cout << std::endl;
}

static void iterators() {
	std::cout << "Iterators : " << std::endl;
	MutantStack<int> mstack;
	for (int i = 0; i < 100; ++i) {
		mstack.push(i);
	}
	const MutantStack<int>& const_stack = mstack;

	std::cout << "const iterator :";
	for (MutantStack<int>::const_iterator it = const_stack.begin();
	     it != const_stack.end(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;

	std::cout << "const reverse iterator :";
	for (MutantStack<int>::const_reverse_iterator it = const_stack.rbegin();
	     it != const_stack.rend(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;

	std::cout << "mut iterator :";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end();
	     ++it) {
		std::cout << " " << *it;
		*it = 42;
	}
	std::cout << std::endl;

	std::cout << "mut reverse iterator :";
	for (MutantStack<int>::reverse_iterator it = mstack.rbegin();
	     it != mstack.rend(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

static void custom() {
	std::cout << "Custom stack with vector :" << std::endl;
	std::vector<int> v;
	for (int i = 0; i < SIZE; ++i)
		v.push_back(i);

	std::cout << "Vector size " << v.size() << std::endl;
	MutantStack<int, std::vector<int> > vector_stack(v);
	std::cout << "Mutant stack size " << vector_stack.size() << std::endl;
	for (int i = 0; i < SIZE; ++i)
		vector_stack.pop();
	std::cout << "Mutant stack size after pops " << vector_stack.size()
	          << std::endl;
	std::cout << std::endl;
}

int main() {
	subject();
	list();
	iterators();
	custom();
}
