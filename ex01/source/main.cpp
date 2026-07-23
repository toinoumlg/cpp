#include "Serializer.hpp"

void isequal(Data* ptr1, Data* ptr2) {
	if (ptr1 != ptr2)
		std::cout << "input and result arent equal" << std::endl;
	else
		std::cout << "input and result are equal" << std::endl;
}

void printdata(Data* ptr) {
	std::cout << "age: " << ptr->age << std::endl
	          << "name: " << ptr->name << std::endl
	          << "city: " << ptr->city << std::endl
	          << std::endl;
}

int main() {
	Data* input = new Data;
	Data* result = NULL;
	uintptr_t raw = 0;

	input->age = 27;
	input->name = "Antoine";
	input->city = "Lyon";

	std::cout << "data address: " << input << std::endl
	          << "deserialize address: " << result << std::endl
	          << "uintptr_t value: " << raw << std::endl
	          << std::endl;

	printdata(input);
	isequal(input, result);

	raw = Serializer::serialize(input);

	std::cout << "uintptr_t value after serialize: " << raw << std::endl;

	result = Serializer::deserialize(raw);

	isequal(input, result);
	printdata(result);
	delete input;
}
