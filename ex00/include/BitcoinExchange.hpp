#pragma once
#include <stdexcept>
#include <vector>

struct Date {
	short year;
	short month;
	short day;
};

typedef std::vector<std::pair<Date, float> > Data;

class BitcoinExchange {
   public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange&);
	BitcoinExchange& operator=(const BitcoinExchange&);
	~BitcoinExchange();

	BitcoinExchange(const char*);

	float GetClosest(const Date& input) const;

   private:
	Data _data;
};

bool operator==(const Date&, const Date&);
bool operator!=(const Date&, const Date&);
bool operator<(const Date&, const Date&);

std::ostream& operator<<(std::ostream&, const Date&);