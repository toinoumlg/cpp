#pragma once

#include <stdint.h>

#include <iostream>
#include <string>

struct Data {
	std::string name;
	std::string city;
	int age;
};

std::ostream& operator<<(std::ostream& s, const Data& data);

class Serializer {
   public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

   private:
	Serializer();
	Serializer& operator=(const Serializer& other);
	Serializer(const Serializer& other);
	~Serializer();
};
