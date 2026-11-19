#pragma once
#include "AForm.hpp"
#include <exception>

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
	~ShrubberyCreationForm();

	class FileErrorException : public std::exception {
		const char *what() const throw() {
			return "Failed to open file for writing";
		}
	};
public:
	std::string getTarget() const;
	unsigned int getSigningGrade() const;
	unsigned int getExecutingGrade() const;
	void execute(Bureaucrat const & executor) const;
private:
	std::string _target;
	static const unsigned int _signingGrade = 145;
	static const unsigned int _executingGrade = 137;
};
