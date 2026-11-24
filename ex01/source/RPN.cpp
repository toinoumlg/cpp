#include "RPN.hpp"

#include <locale>

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
		if (*str != ' ') {
			if (std::isdigit(*str))
				this->push_back(*str - '0');
			else if (is_operand(*str))
				Process(*str);
			else if (*str == ' ')
				continue;
			else
				throw std::exception();
		}
		str++;
	}
}

void RPN::Process(char c) {
	const int right = this->back();
	this->pop_back();
	int left = this->back();
	this->pop_back();

	switch (c) {
		case '*':
			left *= right;
			break;
		case '/':
			left /= right;
			break;
		case '-':
			left -= right;
			break;
		case '+':
			left += right;
			break;
		default:;
	}
	this->push_back(left);
}

int RPN::Result() const { return this->front(); }