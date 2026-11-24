
#include <deque>

#include "PmergeMe.hpp"

int main(int ac, char** av) {
	try {
		if (ac < 2)
			throw std::exception();

		PmergeMe<> vec(&av[1]);
		PmergeMe<std::deque<unsigned int> > deq(&av[1]);

		vec.Merge();
	} catch (std::exception&) {
		std::cerr << "Error" << std::endl;
	}
}