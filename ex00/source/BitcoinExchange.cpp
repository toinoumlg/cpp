#include "BitcoinExchange.hpp"

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>

static Date from_line(const std::string& date) {
	Date res = {};
	char* end = NULL;
	long tmp = std::strtol(&date[0], &end, 10);
	if (std::numeric_limits<short>::max() < tmp ||
	    std::numeric_limits<short>::min() > tmp)
		throw std::exception();

	end++;

	res.year = static_cast<short>(tmp);
	tmp = std::strtol(end, &end, 10);
	if (std::numeric_limits<short>::max() < tmp ||
	    std::numeric_limits<short>::min() > tmp)
		throw std::exception();
	res.month = static_cast<short>(tmp);

	end++;

	tmp = std::strtol(end, &end, 10);
	if (std::numeric_limits<short>::max() < tmp ||
	    std::numeric_limits<short>::min() > tmp)
		throw std::exception();
	res.day = static_cast<short>(tmp);

	return res;
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { (void)other; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (&other != this) {
	}
	return *this;
}

BitcoinExchange::BitcoinExchange(const char* file) {
	char buff[128];
	std::ifstream csv("data.csv", std::ios::in);
	csv.getline(buff, 128);
	_data.reserve(2048);
	if (std::string(buff) != "date,exchange_rate")
		throw std::exception();

	while (!csv.bad()) {
		csv.getline(buff, 128);
		if (csv.eof())
			break;
		std::string line(buff);

		std::size_t coma = line.find(',');
		if (coma == std::string::npos)
			throw std::exception();
		Date date = from_line(line.substr(0, coma));
		char* end = NULL;
		float value = std::strtof(&line.substr(coma + 1, line.size())[0], &end);

		_data.push_back(std::make_pair(date, value));
	}

	std::ifstream input(file, std::ios::in);
	input.getline(buff, 128);
	if (std::string(buff) != "date | value")
		throw std::exception();

	while (!input.bad()) {
		input.getline(buff, 128);
		if (input.eof())
			break;
		std::string line(buff);

		std::size_t coma = line.find(" | ");
		if (coma == std::string::npos) {
			std::cout << "Error : bad input => " << line << std::endl;
			continue;
		}
		Date date = from_line(line.substr(0, coma));
		if (date.month > 12 || date.day > 31) {
			std::cout << "Error: invalid date => " << date << std::endl;
			continue;
		}
		char* end;
		float value = std::strtof(&line.substr(coma + 3, line.size())[0], &end);
		if (value < 0.0f) {
			std::cout << "Error : not a positive number." << std::endl;
			continue;
		}
		if (value > 1000.0f) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		float real = GetClosest(date) * value;
		std::cout << date << " => " << value << " = " << real << std::endl;
	}
}

float BitcoinExchange::GetClosest(const Date& input) const {
	for (Data::const_iterator it = _data.begin(); it != _data.end(); ++it) {
		const Date& lower = it->first;
		Data::const_iterator next = it;
		const Date& upper = (++next)->first;
		if (input == upper)
			return next->second;
		if (lower < input && input < upper)
			return it->second;
	}

	return input.year < 2009 ? 0.0f : _data.back().second;
}

BitcoinExchange::~BitcoinExchange() {}

bool operator==(const Date& first, const Date& second) {
	return first.year == second.year && first.month == second.month &&
	       first.day == second.day;
}

bool operator!=(const Date& first, const Date& second) {
	return first.year != second.year || first.month != second.month ||
	       first.day != second.day;
}

// https://www.reddit.com/r/cpp_questions/comments/17wt3et/date_comparison_using_numbers/
bool operator<(const Date& first, const Date& second) {
	return first.year <= second.year && first.month <= second.month &&
	       first.day <= second.day;
}

//  https://stackoverflow.com/questions/530614/print-leading-zeros-with-c-output-operator
std::ostream& operator<<(std::ostream& s, const Date& date) {
	s << date.year << "-" << std::setw(2) << std::setfill('0') << date.month
	  << "-" << std::setw(2) << std::setfill('0') << date.day;
	return s;
}
