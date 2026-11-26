#include "RPN.hpp"

#include <cctype>
#include <exception>

RPN::RPN() {}

RPN::RPN(const RPN& other) : std::list<int>(other) {}

RPN& RPN::operator=(const RPN& other) {
	if (&other != this)
		std::list<int>::operator=(other);
	return *this;
}

RPN::~RPN() {}

static bool is_operand(char c) {
	return c == '*' || c == '/' || c == '+' || c == '-';
}

RPN::RPN(const char* str) {
	while (*str) {
		if (*str == ' ') {
			str++;
			continue;
		}
		if (str[1] != ' ' && str[1])
			throw std::exception();
		if (std::isdigit(*str))
			this->push_back(*str - '0');
		else if (is_operand(*str))
			Process(*str);
		else
			throw std::exception();
		str++;
	}
	if (this->size() != 1)
		throw std::exception();
}

void RPN::Process(char c) {
	if (this->size() < 2)
		throw std::exception();

	const int right = this->back();
	this->pop_back();
	int left = this->back();
	this->pop_back();

	switch (c) {
		case '*':
			left *= right;
			break;
		case '/':
			if (right == 0)
				throw std::exception();
			left /= right;
			break;
		case '-':
			left -= right;
			break;
		case '+':
			left += right;
			break;
		default:
			throw std::exception();
	}
	this->push_back(left);
}

int RPN::Result() const { return this->front(); }