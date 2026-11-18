#pragma once

#include <iostream>
#include <queue>
#include <stack>

class RPN : std::queue<char> {
   public:
	RPN();
	RPN(const RPN&);
	RPN& operator=(const RPN&);
	~RPN();

	RPN(const char*);
	int Process();
};
