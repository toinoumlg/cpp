#include <iostream>

#include "RPN.hpp"

int main(int ac, char** av) {
	try {
		if (ac != 2)
			throw std::exception();
		const RPN rpn(av[1]);
		std::cout << rpn.Result() << std::endl;
		return 0;
	} catch (std::exception&) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
}
