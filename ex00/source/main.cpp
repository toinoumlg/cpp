#include <iomanip>
#include <iostream>

#include "BitcoinExchange.hpp"

#define SIZE 200

int main(int ac, char** av) {
	if (ac != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	try {
		BitcoinExchange parser(av[1]);
	} catch (std::exception&) {
	}
}
