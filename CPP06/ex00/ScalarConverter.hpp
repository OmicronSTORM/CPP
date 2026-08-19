#pragma once

 #include <iostream>
 #include <string>
 #include <algorithm>
 #include <cmath>

 class ScalarConverter
 {
public:
	static void convert(const std::string &input);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	~ScalarConverter();

	ScalarConverter &operator=(const ScalarConverter &copy);
 };