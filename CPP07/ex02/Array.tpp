#include <stdexcept>

template <typename T>
Array<T>::Array() : _arr(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::~Array()
{
	delete [] _arr;
}

template <typename T>
Array<T>::Array(const Array &copy) : _arr(new T[copy._size]), _size(copy._size)
{
	for (unsigned int i = 0; i < copy._size; i++)
		_arr[i] = copy._arr[i];
}


template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
	if (this != &copy)
	{
		T *newArr = new T[copy._size];
		for (unsigned int i = 0; i < copy._size; i++)
			newArr[i] = copy._arr[i];
		delete[] _arr;
		_arr = newArr;
		_size = copy._size;
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw std::runtime_error("Index out of bounds");
	return (_arr[i]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw std::runtime_error("Index out of bounds");
	return (_arr[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

// template <typename T>
// const char *Array<T>::OutOfBondException::what() const
// {
// 	return ("Index out of bond");
// }
