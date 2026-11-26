#include <iostream>

#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
	try {
		if (ac != 2)
			throw std::exception();

		const BitcoinExchange btc;
		btc.Exec(av[1]);
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
