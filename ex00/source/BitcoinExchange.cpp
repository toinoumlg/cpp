#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

Date::Date() : _year(0), _month(0), _day(0) {}

Date::Date(const Date& other)
    : _year(other._year), _month(other._month), _day(other._day) {}

Date::Date(const std::string& date) {
	if (date.size() != 10)
		throw std::invalid_argument("invalid date format.");
	char* end = NULL;
	long tmp = std::strtol(date.c_str(), &end, 10);
	_year = static_cast<short>(tmp);
	if (std::numeric_limits<short>::max() < tmp ||
	    std::numeric_limits<short>::min() > tmp || *end != '-')
		throw std::invalid_argument("invalid date format.");

	end++;

	tmp = std::strtol(end, &end, 10);
	_month = static_cast<short>(tmp);
	if (std::numeric_limits<short>::max() < tmp ||
	    std::numeric_limits<short>::min() > tmp || *end != '-')
		throw std::invalid_argument("invalid date format.");

	end++;

	tmp = std::strtol(end, &end, 10);
	_day = static_cast<short>(tmp);
	if (std::numeric_limits<short>::max() < tmp ||
	    std::numeric_limits<short>::min() > tmp || *end != '\0')
		throw std::invalid_argument("invalid date format.");

	if (!IsValid())
		throw std::invalid_argument("invalid date format.");
}
Date& Date::operator=(const Date& other) {
	if (this != &other) {
		_year = other._year;
		_month = other._month;
		_day = other._day;
	}
	return *this;
}

bool Date::operator==(const Date& other) const {
	return _year == other._year && _month == other._month && _day == other._day;
}

bool Date::operator!=(const Date& other) const { return !(*this == other); }

// https://www.reddit.com/r/cpp_questions/comments/17wt3et/date_comparison_using_numbers/
bool Date::operator<(const Date& other) const {
	if (_year != other._year)
		return _year < other._year;
	if (_month != other._month)
		return _month < other._month;
	return _day < other._day;
}

std::string Date::ToString() const {
	std::stringstream str;
	str << _year << "-" << std::setw(2) << std::setfill('0') << _month << "-"
	    << std::setw(2) << std::setfill('0') << _day;
	return str.str();
}

bool Date::IsValid() const {
	const bool leap = _year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0);
	static const short days[] = {0,  31, 28, 31, 30, 31, 30,
	                             31, 31, 30, 31, 30, 31};

	if (_year < 1 || _month < 1 || _month > 12 || _day < 1)
		return false;
	if (_day > (_month == 2 && leap ? 29 : days[_month]))
		return false;

	return true;
}

Date::~Date() {}

//  https://stackoverflow.com/questions/530614/print-leading-zeros-with-c-output-operator
std::ostream& operator<<(std::ostream& s, const Date& date) {
	return s << date.ToString();
}

BitcoinExchange::BitcoinExchange() {
	std::string buff;
	std::ifstream csv("data.csv", std::ios::in);
	if (!csv)
		throw std::runtime_error("could not open file.");
	std::getline(csv, buff);
	if (buff != "date,exchange_rate")
		throw std::runtime_error("invalid csv header.");

	while (std::getline(csv, buff)) {
		if (csv.eof())
			break;
		const std::size_t coma = buff.find(',');
		if (coma == std::string::npos)
			throw std::ios_base::failure("missing separator.");

		const Date date(buff.substr(0, coma));
		char* end = NULL;
		const float value =
		    std::strtof(buff.substr(coma + 1, buff.size()).c_str(), &end);

		_data[date] = value;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _data(other._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (&other != this) {
		_data = other._data;
	}
	return *this;
}

void BitcoinExchange::Exec(const char* file_path) const {
	std::string buff;
	std::ifstream input(file_path, std::ios::in);
	std::getline(input, buff);
	if (buff != "date | value")
		throw std::exception();

	while (std::getline(input, buff)) {
		if (input.eof())
			break;

		const std::size_t sep = buff.find(" | ");
		if (sep == std::string::npos) {
			std::cout << "Error: bad input => " << buff << std::endl;
			continue;
		}
		try {
			const Date date(buff.substr(0, sep));
			char* end;
			std::string val_str = buff.substr(sep + 3, buff.size());
			const float value = std::strtof(val_str.c_str(), &end);
			if (val_str.empty() || *end != '\0') {
				std::cout << "Error: bad input => " << buff << std::endl;
				continue;
			}
			if (value < 0.0f) {
				std::cout << "Error: not a positive number." << std::endl;
				continue;
			}
			if (value > 1000.0f) {
				std::cout << "Error: too large a number." << std::endl;
				continue;
			}
			const float real = GetClosest(date) * value;
			std::cout << date << " => " << value << " = " << real << std::endl;
		} catch (const std::exception&) {
			std::cout << "Error: bad input => " << buff << std::endl;
		}
	}
}

float BitcoinExchange::GetClosest(const Date& input) const {
	std::map<Date, float>::const_iterator it = _data.lower_bound(input);
	if (it != _data.end() && it->first == input)
		return it->second;
	if (it == _data.begin())
		return 0.0f;
	return (--it)->second;
}

BitcoinExchange::~BitcoinExchange() {}
