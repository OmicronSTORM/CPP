#include "Span.hpp"

Span::Span() : _size(0)
{
}

Span::Span(unsigned int n) : _size(n)
{
}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		_size = copy._size;
		_tab = copy._tab;
	}
	return (*this);
}

void Span::addNumber(unsigned int n)
{
	if (_tab.size() >= _size)
		throw std::runtime_error("Vector full");
	_tab.push_back(n);
}

void Span::addNumber(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end)
{
	if (_tab.size() >= _size)
		throw std::runtime_error("Vector full");
	for (std::vector<unsigned int>::iterator it = begin; it != end; it++)
	{
		if (_tab.size() >= _size)
			throw std::runtime_error("Vector full");
		_tab.push_back(*it);
	}
}

int Span::shortestSpan()
{
	if (_tab.size() <= 1)
		throw std::runtime_error("Not enough number");
	unsigned int shortest;
	std::vector<unsigned int> tmp = _tab;
	std::sort(tmp.begin(), tmp.end());
	shortest = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < shortest)
			shortest = tmp[i] - tmp[i - 1];
	}
	return (shortest);
}

int Span::longestSpan()
{
	if (_tab.size() <= 1)
		throw std::runtime_error("Not enough number");
	std::vector<unsigned int> tmp = _tab;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}
