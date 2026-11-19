#include "Span.hpp"
#include <iterator>

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

void Span::addNumber(int n)
{
	if (_tab.size() >= _size)
		throw std::runtime_error("Vector full");
	_tab.push_back(n);
}

void Span::addNumber(std::vector<int>::const_iterator begin,
	std::vector<int>::const_iterator end)
{
	std::vector<int>::difference_type count = std::distance(begin, end);
	if (count < 0 || static_cast<unsigned int>(count) > _size - _tab.size())
		throw std::runtime_error("Vector full");
	_tab.insert(_tab.end(), begin, end);
}

unsigned int Span::shortestSpan()
{
	if (_tab.size() <= 1)
		throw std::runtime_error("Not enough number");
	unsigned int shortest;
	std::vector<int> tmp = _tab;
	std::sort(tmp.begin(), tmp.end());
	shortest = static_cast<unsigned int>(tmp[1])
		- static_cast<unsigned int>(tmp[0]);
	for (unsigned int i = 1; i < tmp.size(); i++)
	{
		unsigned int span = static_cast<unsigned int>(tmp[i])
			- static_cast<unsigned int>(tmp[i - 1]);
		if (span < shortest)
			shortest = span;
	}
	return (shortest);
}

unsigned int Span::longestSpan()
{
	if (_tab.size() <= 1)
		throw std::runtime_error("Not enough number");
	std::vector<int> tmp = _tab;
	std::sort(tmp.begin(), tmp.end());
	return (static_cast<unsigned int>(tmp[tmp.size() - 1])
		- static_cast<unsigned int>(tmp[0]));
}
