#include "ScalarConverter.hpp"

bool isChar(const std::string& value) {
	return value.length() == 1 && !std::isdigit(value.at(0));
}

bool isInt(const std::string& value) {
	errno = 0;
	char* end = NULL;
	std::strtol(value.c_str(), &end, 10);
	if (errno != 0 || std::strlen(end) > 0)
		return false;
	return true;
}

bool isFloat(const std::string& value) {
	errno = 0;
	char* end = NULL;
	std::strtof(value.c_str(), &end);
	if (errno != 0 || std::strlen(end) != 1 || *end != 'f')
		return false;
	return true;
}

bool isDouble(const std::string& value) {
	errno = 0;
	char* end = NULL;
	std::strtod(value.c_str(), &end);
	if (errno != 0 || std::strlen(end) > 0)
		return false;
	return true;
}

e_type findType(const std::string& value) {
	if (value.empty())
		return INVALID;

	if (isChar(value))
		return CHAR;
	if (isInt(value))
		return INT;
	else if (isDouble(value))
		return DOUBLE;
	else if (isFloat(value))
		return FLOAT;
	return INVALID;
}