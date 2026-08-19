#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor for ScalarConverter has been called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
	std::cout << "Copy constructor has been called for ScalarConverter" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor for ScalarConverter has been called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (this != &copy)
		*this = copy;
	return (*this);
}

int detectChar(const std::string &input)
{
	if (input.length() > 1)
		return (0);
	if (!isalpha(input[0]))
		return (0);
	return (1);
}

int detectInt(const std::string &input)
{
	for (int i = 0; input[i]; i++)
		if (!isdigit(input[i]))
			return (0);
	return (1);
}

int detectFloat(const std::string &input)
{
	int dotCounter = 0;
	if (input[input.length() - 1] != 'f')
		return (0);
	if (input.compare("inff") || input.compare("+inff") || input.compare("-inff") || input.compare("nanf"))
		return (1);
	if (input[0] == '.' || input[input.length() - 2] == '.')
		return (0);
	for (int i = 0; i < (int)input.length() - 1; i++)
	{
		if (!isdigit(input[i]) && input[i] != '.')
			return (0);
		if (input[i] == '.')
			dotCounter++;
		if (dotCounter > 1)
			return (0);
	}
	return (1);
}

int detectDouble(const std::string &input)
{
	int dotCounter = 0;
	if (input.compare("inf") || input.compare("+inf") || input.compare("-inf") || input.compare("nan"))
		return (1);
	if (input[0] == '.' || input[input.length() - 1] == '.')
		return (0);
	for (int i = 0; i < (int)input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '.')
			return (0);
		if (input[i] == '.')
			dotCounter++;
		if (dotCounter > 1)
			return (0);
	}
	return (1);
}

char detectType(const std::string &input)
{
	if (detectChar(input))
		return ('c');
	if (detectInt(input))
		return ('i');
	if (detectFloat(input))
		return ('f');
	if (detectDouble(input))
		return ('d');
	return ('e');
}

void invalidInput()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void displayChar(char c, double d)
{
	if (d > 128 || d < 0 || std::isnan(d))
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else if (c >= 0 && c <= 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

void displayInt(int i)
{
	if (i <= 2147483647 && i > -2147483648)
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void displayFloat(float f)
{
	if (static_cast<long long int>(f) - f != 0)
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " << f << ".0f" << std::endl;
}

void displayDouble(double d)
{
	if (static_cast<long long int>(d) - d != 0)
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;
}

void displayVariables(char c, int i, float f, double d)
{
	displayChar(c, d);
	displayInt(i);
	displayFloat(f);
	displayDouble(d);
}

void convertOriginType(char type, const std::string &input)
{
	if (type == 'c')
	{
		char c = input[0];
		int i = c;
		float f = static_cast<float>(c);
		double d = static_cast<double>(c);
		displayVariables(c, i, f, d);
	}
	else if (type == 'i')
	{
		int i = std::strtol(input.c_str(), NULL, 10);
		char c = i;
		float f = static_cast<float>(i);
		double d = static_cast<double>(i);
		displayVariables(c, i, f, d);
	}
	else if (type == 'f')
	{
		float f = std::strtof(input.c_str(), NULL);
		int i = static_cast<int>(f);
		char c = static_cast<char>(f);
		double d = static_cast<double>(f);
		displayVariables(c, i, f, d);
	}
	else if (type == 'd')
	{
		double d = std::strtod(input.c_str(), NULL);
		int i = static_cast<int>(d);
		char c = static_cast<char>(d);
		float f = static_cast<float>(d);
		displayVariables(c, i, f, d);
	}
}

void ScalarConverter::convert(const std::string &input)
{
	char type = detectType(input);
	if (type == 'e')
	{
		invalidInput();
		return ;
	}
	convertOriginType(type, input);
}