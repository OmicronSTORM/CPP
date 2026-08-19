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

	void addNumber(unsigned int n);
	void addNumber(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end);

	int shortestSpan();
	int longestSpan();

private:
	unsigned int			   _size;
	std::vector<unsigned int>  _tab;
};
