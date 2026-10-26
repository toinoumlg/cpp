#include "Serializer.hpp"

void compare(const Data* a, const Data* b) {
	std::cout << "data1: " << a << (a == b ? " == " : " != ") << "data2: " << b
	          << std::endl
	          << std::endl;
}

int main() {
	Data input;
	Data* result = NULL;
	uintptr_t raw = 0;

	input.age = 27;
	input.name = "Antoine";
	input.city = "Lyon";

	std::cout << "data address: " << &input << std::endl
	          << "deserialize address: " << result << std::endl
	          << "uintptr_t value: " << raw << std::endl
	          << std::endl;

	compare(&input, result);

	std::cout << input << std::endl << std::endl;

	raw = Serializer::serialize(&input);

	std::cout << "uintptr_t value after serialize: " << raw << std::endl
	          << std::endl;

	result = Serializer::deserialize(raw);

	compare(&input, result);

	std::cout << *result << std::endl << std::endl;
	input.age = 0;
	std::cout << *result << std::endl << std::endl;
}
