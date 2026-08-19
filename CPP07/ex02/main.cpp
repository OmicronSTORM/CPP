#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> emptyArray;
	std::cout << "size of empty array: " << emptyArray.size() << std::endl;
	Array<int> intArray(6);
	std::cout << "size of int array: " << intArray.size() << std::endl;
	for (unsigned int i = 0; i < intArray.size(); i++)
		intArray[i] = i;
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << "number in the array: " << intArray[i] << std::endl;
	return (0);
}
