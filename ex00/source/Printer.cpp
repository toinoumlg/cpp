#include "ScalarConverter.hpp"

void impossible() {
	std::cout << "char: impossible" << std::endl
	          << "int: impossible" << std::endl
	          << "float: impossible" << std::endl
	          << "double: impossible" << std::endl;
}

void toChar(double d) {
	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d) ||
	    d < static_cast<double>(std::numeric_limits<char>::min()) ||
	    d > static_cast<double>(std::numeric_limits<char>::max()))
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(d)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(d) << std::endl;
}

void toInt(double d) {
	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d) ||
	    d < static_cast<double>(std::numeric_limits<int>::min()) ||
	    d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
}

void toFloat(double d) {
	std::cout << "float: ";
	if (std::isnan(d))
		std::cout << "nanf" << std::endl;
	else if (d == std::numeric_limits<double>::infinity())
		std::cout << "+inff" << std::endl;
	else if (d == -std::numeric_limits<double>::infinity())
		std::cout << "-inff" << std::endl;
	else if (d > static_cast<double>(std::numeric_limits<float>::max()) ||
	         d < -static_cast<double>(std::numeric_limits<float>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(d) << "f" << std::endl;
}

void toDouble(double d) {
	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan" << std::endl;
	else if (d == std::numeric_limits<double>::infinity())
		std::cout << "+inf" << std::endl;
	else if (d == -std::numeric_limits<double>::infinity())
		std::cout << "-inf" << std::endl;
	else
		std::cout << d << std::endl;
}
