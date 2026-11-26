
#include <iostream>

#include "PmergeMe.hpp"

int main(int ac, char** av) {
	try {
		if (ac < 2)
			throw std::exception();

		PmergeMe::before(&av[1]);

		PmergeMe merger;
		merger.mergeVec(&av[1]);
		merger.mergeDeq(&av[1]);

		merger.after();

		return 0;
	} catch (std::exception&) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
}