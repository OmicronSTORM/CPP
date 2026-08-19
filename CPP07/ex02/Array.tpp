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
		delete[] this._arr;
		this._arr = new T[copy._size];
		this._size = copy._size;
		for (int i = 0; i < copy._size; i++)
			this._arr[i] = copy._arr[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw std::runtime_error("Index out of bond");
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
