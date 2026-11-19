#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base *generate(void)
{
	static bool seeded = false;
	if (!seeded)
	{
		srand(time(NULL));
		seeded = true;
	}
		
	int i = rand() % 3;

	if (i == 0)
		return (new A);
	if (i == 1)
		return (new B);
	if (i == 2)
		return (new C);
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		return (std::cout << "A" << std::endl, (void)0);
	else if (dynamic_cast<B*>(p))
		return (std::cout << "B" << std::endl, (void)0);
	else if (dynamic_cast<C*>(p))
		return (std::cout << "C" << std::endl, (void)0);
	std::cout << "Base" << std::endl;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		return (std::cout << "A" << std::endl, (void)0);
	}
	catch (const std::exception &e)
	{}
	try
	{
		dynamic_cast<B&>(p);
		return (std::cout << "B" << std::endl, (void)0);
	}
	catch (const std::exception &e)
	{}
	try
	{
		dynamic_cast<C&>(p);
		return (std::cout << "C" << std::endl, (void)0);
	}
	catch (const std::exception &e)
	{}
	std::cout << "Base" << std::endl;
}