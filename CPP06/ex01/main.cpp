#include "Serializer.hpp"

int main()
{
	Data *ptr = new Data;
	uintptr_t raw;

	ptr->c = 'm';
	ptr->i = 19;
	ptr->str = "Hindsighttt";
	raw = Serializer::serialize(ptr);
	Data *new_ptr = Serializer::deserialize(raw);

	std::cout << "new_ptr c: " << new_ptr->c << std::endl;
	std::cout << "new_ptr i: " << new_ptr->i << std::endl;
	std::cout << "new_ptr str: " << new_ptr->str << std::endl;
	delete ptr;
	return (0);
}