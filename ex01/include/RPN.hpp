#pragma once

#include <list>

class RPN : std::list<int> {
   public:
	RPN();
	RPN(const RPN&);
	RPN& operator=(const RPN&);
	~RPN();

	RPN(const char*);
	void Process(char c);
	int Result() const;
};
