#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <exception>

int main() {
	std::cout << "[GIVING BIRTH TO BUREAUCRAT]" << std::endl;
	try {
		Bureaucrat high("Too High", 0);
	}
	catch (std::exception &e) {
		std::cout << "Couldn't birth this bureaucrat: " << e.what() << std::endl;
	}

	try {
		Bureaucrat low("Too Low", 200);
	}
	catch (std::exception &e) {
		std::cout << "Couldn't birth this bureaucrat: " << e.what() << std::endl;
	}

	Bureaucrat regular("Regular", 25);
	Bureaucrat highAutority("GOD", 1);
	std::cout << regular << std::endl;
	std::cout << highAutority << std::endl;

	std::cout << std::endl << "[PRINTING FORMS]" << std::endl;

	AForm *shrubbery = new ShrubberyCreationForm("test");
	AForm *presidentialPardonForm = new PresidentialPardonForm("NBA Young boy");
	AForm *robotomyRequestForm = new RobotomyRequestForm("The opps");

	std::cout << *shrubbery << std::endl;
	std::cout << *presidentialPardonForm << std::endl;
	std::cout << *robotomyRequestForm << std::endl;

	std::cout << std::endl << "[TESTING FORMS]" << std::endl;
	try {
		shrubbery->execute(regular);
	}
	catch (std::exception &e) {
		std::cout << "Failed to execute form: " << e.what() << std::endl;
	}

	regular.signForm(*shrubbery);
	shrubbery->execute(regular);
	presidentialPardonForm->beSigned(regular);
	try {
		regular.executeForm(*presidentialPardonForm);
	}
	catch (std::exception &e) {
		std::cout << "#FREENBAYOUNGBOY: " << e.what() << std::endl;
	}

	
	highAutority.signForm(*robotomyRequestForm);
	for (int i = 0; i < 5; i++) {
		try {
			highAutority.executeForm(*robotomyRequestForm);
		}
		catch (std::exception &e) {
			std::cout << "Robotomy failed: " << e.what() << std::endl;
		}
	}

	delete robotomyRequestForm;
	delete presidentialPardonForm;
	delete shrubbery;
	return 0;
}
