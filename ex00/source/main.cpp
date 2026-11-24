#include <iostream>

#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
	if (ac != 2) {
		std::cout << "Error: missing ." << std::endl;
		return 1;
	}

	try {
		const BitcoinExchange btc;
		btc.Exec(av[1]);
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
