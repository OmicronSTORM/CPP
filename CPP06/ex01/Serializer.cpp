#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Default constructor for Serializer has been called" << std ::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	*this = copy;
	std::cout << "Copy constructor for Serializer has been called" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Destructor for Serializer has been called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &copy)
{
	(void)copy;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}