#pragma once

#include <cstdint>
#include <iostream>
#include <string>

struct Data {
	std::string name;
	std::string city;
	int age;
};

class Serializer {
   private:
	Serializer();
	Serializer& operator=(const Serializer& other);
	Serializer(const Serializer& other);
	~Serializer();

   public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
