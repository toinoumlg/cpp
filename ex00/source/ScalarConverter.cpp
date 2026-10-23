#include "ScalarConverter.hpp"

int ScalarConverter::convert(const std::string &value) {
	std::cout << std::fixed << std::setprecision(1);

	switch (findType(value)) {
		case CHAR:
			fromChar(value);
			break;
		case INT:
			fromInt(value);
			break;
		case FLOAT:
			fromFloat(value);
			break;
		case DOUBLE:
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
