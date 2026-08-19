template <typename T>
typename T::iterator easyfind(T &container, const int n)
{
	typename T::iterator it;

	it = find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::runtime_error("no iteration");
	return (it);
}

