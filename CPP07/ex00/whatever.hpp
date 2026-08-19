#pragma once

template <typename T>
void swap(T &src, T &dest)
{
	T tmp;

	tmp = src;
	src = dest;
	dest = tmp;
}

template <typename T>
T min(const T &val1, const T &val2)
{
	if (val1 < val2)
		return (val1);
	if (val1 > val2)
		return (val2);
	return (val2);
}

template <typename T>
T max(const T &val1, const T &val2)
{
	if (val1 < val2)
		return (val2);
	if (val1 > val2)
		return (val1);
	return (val2);
}