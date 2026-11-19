#pragma once

template <typename T>
void swap(T &src, T &dest)
{
	T tmp = src;
	src = dest;
	dest = tmp;
}

template <typename T>
const T &min(const T &val1, const T &val2)
{
	return (val1 < val2 ? val1 : val2);
}

template <typename T>
const T &max(const T &val1, const T &val2)
{
	return (val2 < val1 ? val1 : val2);
}