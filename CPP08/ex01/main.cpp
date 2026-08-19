#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "Try exception" << std::endl;
	try
	{
		sp.addNumber(78);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;	
	}
	std::cout << "----------------" << std::endl;
	Span sp2 = Span(10);
	std::vector<unsigned int> array;
	array.push_back(1);
	array.push_back(2);
	array.push_back(54);
	sp2.addNumber(array.begin(), array.end());
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	return 0;
}
