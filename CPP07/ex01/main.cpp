#include "iter.hpp"
#include <iostream>

template <typename T>
void plus(T const &c)
{
	std::cout << c + 1 << std::endl;
}

class test{
public:
	int a;
};

std::ostream& operator<<(std::ostream& stream, test const &value) {
	stream << value.a;
	return stream;
}

template <typename T>
void func(T const &c)
{
	std::cout << c << std::endl;
}

int main()
{
	std::string array = "hello";
	std::cout << "string en parametre" << std::endl;
	iter(array.c_str(), array.length(), func);

	int i[3] = {1, 2, 3};
	std::cout << "int en parametre" << std::endl;
	iter(i, 3, func);
	std::cout << "int en parametre avec une autre fonction" << std::endl;
	iter(i, 3, plus);
	
	test arr[2] = {75, 76};
	std::cout << "class en parametre" << std::endl;
	iter(arr, 2, func);
	return (0);
}