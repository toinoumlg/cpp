#include "Serializer.hpp"

void isequal(Data* ptr1, Data* ptr2) {
	if (ptr1 != ptr2)
		std::cout << "data 1: " << ptr1 << " != data 2: " << ptr2 << std::endl
		          << std::endl;
	else
		std::cout << "data 1: " << ptr1 << " == data 2: " << ptr2 << std::endl
		          << std::endl;
}

void printdata(Data* ptr) {
	if (!ptr)
		return;
	std::cout << "age: " << ptr->age << std::endl
	          << "name: " << ptr->name << std::endl
	          << "city: " << ptr->city << std::endl
	          << "adress: " << ptr << std::endl
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

	std::cout << "uintptr_t value after serialize: " << raw << std::endl
	          << std::endl;

	result = Serializer::deserialize(raw);

	isequal(input, result);
	printdata(result);
	delete input;
}
