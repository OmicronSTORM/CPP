#pragma once
#include "AForm.hpp"

class Intern {
public:
	Intern();
	Intern(Intern const &);
	Intern &operator=(Intern const &);
	~Intern();
public:
	AForm *makeForm(std::string type, std::string target) ;
private:
	AForm *makeShrubberyCreationForm(std::string target);
	AForm *makePresidentialPardonForm(std::string target);
	AForm *makeRobotomyRequestForm(std::string target);
};

