#include <iostream>

#include "RPN.hpp"

int main(int ac, char** av) {
	if (ac != 2)
		return 1;
	try {
		const RPN rpn(av[1]);
		std::cout << rpn.Result() << std::endl;
	} catch (std::exception&) {
		std::cerr << "Error" << std::endl;
	}
}
