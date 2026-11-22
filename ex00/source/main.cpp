#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <set>
#include <vector>

#include "easyfind.hpp"
#define SIZE 200

template <typename C>
static void try_catch(const C& container, int value) {
	try {
		typename C::const_iterator it = easyfind(container, value);
		std::cout << "[const] found => " << *it << std::endl;
	} catch (const not_found& e) {
		std::cout << e.what() << " " << e.value() << std::endl;
	}
}

template <typename C>
static void try_catch(C& container, int value) {
	try {
		typename C::iterator it = easyfind(container, value);
		std::cout << "[mut] found => " << *it << std::endl;
	} catch (const not_found& e) {
		std::cout << e.what() << " " << e.value() << std::endl;
	}
}

int main() {
	std::srand(time(NULL));
	std::vector<int> vec;
	std::set<int> set;
	std::deque<int> deq;
	std::list<int> list;

	for (int i = 0; i < SIZE; ++i) {
		vec.push_back(i);
		set.insert(set.begin(), i * (i % 2 == 0 ? 1 : -1));
		deq.push_front(i * i);
		list.push_back(rand());
	}

	std::cout << "Random test :" << std::endl;
	try_catch(vec, 5);
	try_catch(vec, 42);
	try_catch(deq, 9);
	try_catch(deq, 20);
	try_catch(list, 150);
	try_catch(list, 155);
	try_catch(set, -19);
	try_catch(set, -10);
	std::cout << std::endl;

	const std::set<int> const_set(set);
	const std::set<int> empty;
	const std::vector<int> const_vec(vec);

	std::cout << "Mutate :" << std::endl;
	std::vector<int>::iterator it = easyfind(vec, 5);
	*it = 1000;
	try_catch(vec, 5);
	try_catch(vec, 1000);
	std::cout << std::endl;


	std::cout << "Random test" << std::endl;
	try_catch(vec, 5);
	try_catch(const_set, 9);
	try_catch(empty, 5);
	try_catch(const_set, 50);
	try_catch(deq, 9);
	try_catch(set, 0);
	try_catch(set, -10);
	try_catch(deq, 10000);
	try_catch(set, -199);
	try_catch(vec, 150);
	try_catch(list, 1741);
	try_catch(list, rand());
	try_catch(list, 12398);
	try_catch(deq, 20);
	try_catch(empty, 0);
	try_catch(const_vec, 0);
	try_catch(const_vec, 34971);
}
