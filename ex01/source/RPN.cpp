#include "RPN.hpp"
RPN::RPN() {}
RPN::RPN(const RPN& other) : std::queue<char>(other) {}
RPN& RPN::operator=(const RPN& other) {
	if (&other != this) {
		std::queue<char>::operator=(other);
	}
	return *this;
}
RPN::~RPN() {}
RPN::RPN(const char* str) {
	while (*str) {
		if (*str != ' ')
			this->push(*str);
		str++;
	}
}
int RPN::Process() {
	this->pop_front();
	return 0;
}