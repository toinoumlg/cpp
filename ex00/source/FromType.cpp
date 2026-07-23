#include "ScalarConverter.hpp"

void fromChar(const std::string& value) {
	char c = value.at(0);

	toChar(static_cast<double>(c));
	toInt(static_cast<double>(c));
	toFloat(static_cast<double>(c));
	toDouble(static_cast<double>(c));
}

void fromInt(const std::string& value) {
	long l = std::atol(value.c_str());
	if (l < std::numeric_limits<int>::min() ||
	    l > std::numeric_limits<int>::max())
		return impossible();

	toChar(static_cast<double>(l));
	toInt(static_cast<double>(l));
	toFloat(static_cast<double>(l));
	toDouble(static_cast<double>(l));
}

void fromFloat(const std::string& value) {
	float f = std::strtof(value.c_str(), NULL);

	toChar(static_cast<double>(f));
	toInt(static_cast<double>(f));
	toFloat(static_cast<double>(f));
	toDouble(static_cast<double>(f));
}

void fromDouble(const std::string& value) {
	double d = std::strtod(value.c_str(), NULL);

	toChar(d);
	toInt(d);
	toFloat(d);
	toDouble(d);
}