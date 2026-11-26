#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <stdexcept>

class Date {
   public:
	Date();
	Date(const Date&);
	Date(const std::string&);

	Date& operator=(const Date&);
	~Date();

	bool IsValid() const;
	bool operator==(const Date&) const;
	bool operator!=(const Date&) const;
	bool operator<(const Date&) const;

	std::string ToString() const;

   private:
	short _year;
	short _month;
	short _day;
};

class BitcoinExchange {
   public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange&);
	BitcoinExchange& operator=(const BitcoinExchange&);
	~BitcoinExchange();

	void Exec(const char* file_path) const;

   private:
	float GetClosest(const Date& input) const;

	std::map<Date, float> _data;
};

std::ostream& operator<<(std::ostream&, const Date&);

#endif
