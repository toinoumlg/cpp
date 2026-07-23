#include "ScalarConverter.hpp"

int ScalarConverter::convert(const std::string &value) {
	std::cout << std::fixed << std::setprecision(1);

	switch (findType(value)) {
		case CHAR:
			fromChar(value);
			break;
		case INT:
			std::cout << "int" << std::endl;
			fromInt(value);
			break;
		case FLOAT:
			std::cout << "float" << std::endl;
			fromFloat(value);
			break;
		case DOUBLE:
			std::cout << "double" << std::endl;

			fromDouble(value);
			break;
		case INVALID:
			return 1;
	}
	return 0;
}

// Orthodox Canonical Form even if not instantiable
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}
