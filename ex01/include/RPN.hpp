#ifndef RPN_H
#define RPN_H

#include <list>

class RPN : public std::list<int> {
   public:
	RPN();
	RPN(const RPN&);
	RPN& operator=(const RPN&);
	~RPN();

	RPN(const char*);
	void Process(char c);
	int Result() const;
};

#endif
