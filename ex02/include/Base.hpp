#pragma once

class Base {
   public:
	virtual ~Base() {}
};

Base* generate();
void identity(Base*);
void identity(Base&);
