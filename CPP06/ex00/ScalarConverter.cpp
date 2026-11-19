#include "ScalarConverter.hpp"

#include <cctype>
#include <cstdlib>
#include <limits>
#include <sstream>

static bool isNumeric(const std::string &input, bool floatSuffix)
{
	size_t end = input.length();
	if (floatSuffix)
	{
		if (end < 2 || input[end - 1] != 'f')
			return (0);
		end--;
	}
	if (end == 0)
		return (0);
	size_t i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	size_t digits = 0;
	while (i < end && std::isdigit(static_cast<unsigned char>(input[i])))
	{
		i++;
		digits++;
	}
	if (i < end && input[i] == '.')
	{
		i++;
		while (i < end && std::isdigit(static_cast<unsigned char>(input[i])))
		{
			i++;
			digits++;
		}
	}
	if (digits == 0)
		return (0);
	if (i < end && (input[i] == 'e' || input[i] == 'E'))
	{
		i++;
		if (i < end && (input[i] == '+' || input[i] == '-'))
			i++;
		size_t exponentStart = i;
		while (i < end && std::isdigit(static_cast<unsigned char>(input[i])))
			i++;
		if (i == exponentStart)
			return (0);
	}
	return (i == end);
}

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
	(void)copy;
	return (*this);
}

int detectChar(const std::string &input)
{
	if (input.length() != 1)
		return (0);
	if (std::isdigit(static_cast<unsigned char>(input[0])))
		return (0);
	return (1);
}

int detectInt(const std::string &input)
{
	if (input.empty())
		return (0);
	size_t i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (i == input.length())
		return (0);
	for (; i < input.length(); i++)
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return (0);
	return (1);
}

int detectFloat(const std::string &input)
{
	if (input == "inff" || input == "+inff" || input == "-inff"
		|| input == "nanf")
		return (1);
	return (isNumeric(input, true));
}

int detectDouble(const std::string &input)
{
	if (input == "inf" || input == "+inf" || input == "-inf"
		|| input == "nan")
		return (1);
	return (isNumeric(input, false));
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

void displayChar(double d)
{
	if (std::isnan(d) || std::isinf(d))
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	double truncated = d < 0 ? std::ceil(d) : std::floor(d);
	if (truncated < 0 || truncated > 127)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	char c = static_cast<char>(static_cast<int>(truncated));
	if (std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void displayInt(double d)
{
	if (std::isnan(d) || std::isinf(d))
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	double truncated = d < 0 ? std::ceil(d) : std::floor(d);
	if (truncated < std::numeric_limits<int>::min()
		|| truncated > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(d) << std::endl;
}

void displayFloat(double d)
{
	if (std::isnan(d))
	{
		std::cout << "float: nanf" << std::endl;
		return ;
	}
	if (std::isinf(d))
	{
		std::cout << "float: " << (d < 0 ? "-inff" : "inff") << std::endl;
		return ;
	}
	if (d < -std::numeric_limits<float>::max()
		|| d > std::numeric_limits<float>::max())
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	float f = static_cast<float>(d);
	std::ostringstream output;
	output << f;
	std::string value = output.str();
	if (std::floor(f) == f)
	{
		size_t exponent = value.find_first_of("eE");
		if (value.find('.') == std::string::npos)
			value.insert(exponent == std::string::npos ? value.length() : exponent,
				".0");
	}
	std::cout << "float: " << value << "f" << std::endl;
}

void displayDouble(double d)
{
	if (std::isnan(d))
	{
		std::cout << "double: nan" << std::endl;
		return ;
	}
	if (std::isinf(d))
	{
		std::cout << "double: " << (d < 0 ? "-inf" : "inf") << std::endl;
		return ;
	}
	std::ostringstream output;
	output << d;
	std::string value = output.str();
	if (std::floor(d) == d)
	{
		std::string::size_type exponent = value.find_first_of("eE");
		if (value.find('.') == std::string::npos)
			value.insert(exponent == std::string::npos ? value.length() : exponent,
				".0");
	}
	std::cout << "double: " << value << std::endl;
}

void displayVariables(double d)
{
	displayChar(d);
	displayInt(d);
	displayFloat(d);
	displayDouble(d);
}

void convertOriginType(char type, const std::string &input)
{
	if (type == 'c')
	{
		double d = static_cast<unsigned char>(input[0]);
		displayVariables(d);
	}
	else if (type == 'i')
	{
		double d = std::strtod(input.c_str(), NULL);
		displayVariables(d);
	}
	else if (type == 'f')
	{
		float f = std::strtof(input.c_str(), NULL);
		displayVariables(static_cast<double>(f));
	}
	else if (type == 'd')
	{
		double d = std::strtod(input.c_str(), NULL);
		displayVariables(d);
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