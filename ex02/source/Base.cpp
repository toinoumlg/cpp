#include "Base.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
	switch (rand() % 3) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return new A();
	}
}

void identity(Base* p) {
	std::cout << "object pointed to by p: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	if (dynamic_cast<B*>(p))
		std::cout << "B";
	if (dynamic_cast<C*>(p))
		std::cout << "C";
	std::cout << std::endl;
}

void identity(Base& p) {
	std::cout << "object referenced by p: ";
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A";
	} catch (std::bad_cast&) {
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B";
	} catch (std::bad_cast&) {
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C";
	} catch (std::bad_cast&) {
	}
	std::cout << std::endl;
}