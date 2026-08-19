#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, const int n);

#include "easyfind.tpp"
