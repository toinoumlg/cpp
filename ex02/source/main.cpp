#include <cstdlib>
#include <iostream>

#include "Base.hpp"

int main() {
	srand(time(NULL));

	Base *a = generate();
	Base *b = generate();
	Base *c = generate();
	Base *d = generate();
	Base *e = generate();
	Base *f = generate();

	identity(a);
	identity(b);
	identity(c);
	identity(d);
	identity(e);
	identity(f);

	std::cout << std::endl;

	identity(*a);
	identity(*b);
	identity(*c);
	identity(*d);
	identity(*e);
	identity(*f);
}