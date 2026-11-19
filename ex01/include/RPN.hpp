#pragma once

#include <queue>

class RPN : std::deque<int> {
   public:
	RPN();
	RPN(const RPN&);
	RPN& operator=(const RPN&);
	~RPN();

	RPN(const char*);
	void Process(char c);
	int Result() const;
};
