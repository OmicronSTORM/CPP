#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
	std::cout << "[Intern::Intern]: Default constructor called" << std::endl;
}

Intern::Intern(Intern const &) {
	std::cout << "[Intern::Intern]: Copy constructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &) {
	std::cout << "[Intern::operator=]: Copy assignement operator called" << std::endl;
	return *this;
}

Intern::~Intern() {
	std::cout << "[Intern::~Intern]: Destructor called" << std::endl;
}

AForm *Intern::makeForm(std::string type, std::string target) {
	AForm *form = NULL;
	std::string formNames[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	AForm *(Intern::*function[3])(std::string) = {&Intern::makeShrubberyCreationForm, &Intern::makePresidentialPardonForm, &Intern::makeRobotomyRequestForm};

	std::string lower;
	for (int i = 0; i < (int)type.length(); i++) {
		lower += (tolower(type[i]));
	}
	for (int i = 0; i < 3; i++) {
		if (formNames[i].compare(lower.c_str()) == 0) {
			form = ((this->*function[i])(target));
			std::cout << "Intern creates " << form->getName() << std::endl;
			break;
		}
	}
	
	if (!form)
		std::cout << "[Intern::makeForm]: No matching form found" << std::endl;
	return form;
}

AForm *Intern::makeShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makePresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}
