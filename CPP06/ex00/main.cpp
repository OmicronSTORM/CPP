#include "ScalarConverter.hpp"

#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 2)
		ScalarConverter::convert(av[1]);
	else
	{
		std::cerr << "Error: expected exactly one argument" << std::endl;
		return (1);
	}
	return (0);
}