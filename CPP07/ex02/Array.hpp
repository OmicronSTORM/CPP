#pragma once
#include <exception>

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(const Array &copy);
	~Array();

	Array &operator=(const Array &copy);
	T &operator[](unsigned int i);
	const T &operator[](unsigned int i) const;

	unsigned int size() const;

	// class OutOfBondException : public std::exception
	// {
	// public:
	// 	virtual const char *what() const throw();
	// };

private:
	T				*_arr;
	unsigned int	_size;
};

#include "Array.tpp"
