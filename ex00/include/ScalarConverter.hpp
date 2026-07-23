#pragma once

#include <cerrno>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <typeinfo>

enum e_type {
	INVALID = -1,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
};

class ScalarConverter {
   private:
	ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& other);
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();

   public:
	static int convert(const std::string& value);
};

// publics methods
e_type findType(const std::string& values);
void fromInt(const std::string& value);
void fromChar(const std::string& value);
void fromFloat(const std::string& value);
void fromDouble(const std::string& value);
void toChar(double d);
void toInt(double d);
void toFloat(double d);
void toDouble(double d);
void impossible();