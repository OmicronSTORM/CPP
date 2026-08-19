#pragma once

#include <iostream>
#include <stdint.h>

typedef struct Data
{
	int i;
	char c;
	std::string str;
} Data;

class Serializer
{
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(const Serializer &copy);
	~Serializer();

	Serializer &operator=(const Serializer &copy);
};