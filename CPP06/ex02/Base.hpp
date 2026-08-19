#pragma once

#include <iostream>
#include <exception>
#include <cstdlib>
#include <cstddef>

class Base
{
public:
	virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);