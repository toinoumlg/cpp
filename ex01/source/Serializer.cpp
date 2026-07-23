#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr) {
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data *Serializer::deserialize(uintptr_t raw) {
	Data *test = reinterpret_cast<Data *>(raw);
	return test;
}

// Orthodox Canonical Form even if not instantiable
Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other) { *this = other; }

Serializer &Serializer::operator=(const Serializer &other) {
	(void)other;
	return *this;
}

Serializer::~Serializer() {}
