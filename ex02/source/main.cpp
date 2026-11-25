
#include <iostream>

#include "PmergeMe.hpp"

int main(int ac, char** av) {
	try {
		if (ac < 2)
			throw std::exception();

		PmergeMe merger;
		merger.before(&av[1]);

		merger.mergeVec(&av[1]);
		merger.mergeDeq(&av[1]);

		merger.after();

	} catch (std::exception&) {
		std::cerr << "Error" << std::endl;
	}
}