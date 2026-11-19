#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>

class Span
{
public:
	Span();
	Span(unsigned int n);
	Span(const Span &copy);
	~Span();

	Span &operator=(const Span &copy);

	void addNumber(int n);
	void addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);

	unsigned int shortestSpan();
	unsigned int longestSpan();

private:
	unsigned int			   _size;
	std::vector<int>		   _tab;
};
