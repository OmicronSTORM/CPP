#include "easyfind.hpp"
#include <exception>

int main()
{
	std::cout << "-------------- Vector container -------------" << std::endl;
	std::vector<int> vecInt;
	for (int i = 0; i < 10; i++)
		vecInt.push_back(i);
	try
	{
		std::cout << *easyfind(vecInt, 4) << std::endl;
		std::cout << *easyfind(vecInt, 20) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------- Deque container ---------------" << std::endl;
	std::deque<int> deqInt;
	for (int i = 0; i < 15; i++)
		deqInt.push_back(i);
	try
	{
		std::cout << *easyfind(deqInt, 14) << std::endl;
		std::cout << *easyfind(deqInt, 4) << std::endl;
		std::cout << *easyfind(deqInt, -1) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------- List container ----------------" << std::endl;
	std::list<int> listInt;
	for (int i = 5; i < 20; i++)
		listInt.push_back(i);
	try
	{
		std::cout << *easyfind(listInt, 5) << std::endl;
		std::cout << *easyfind(listInt, 17) << std::endl;
		std::cout << *easyfind(listInt, 2) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
