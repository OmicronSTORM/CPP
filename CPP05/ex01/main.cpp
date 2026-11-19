#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <ostream>

int main() {
	try {
		Bureaucrat high("Too High", 0);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Bureaucrat low("Too Low", 200);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	Bureaucrat regular("Regular", 25);
	std::cout << regular << std::endl;
	Form defaultForm;
	std::cout << defaultForm << std::endl;

	try {
		Form high_form("high", 0, 0);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Form low_form("low", 151, 200);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}


	std::cout << std::endl <<"[Attempting to sign forms]"<< std::endl;
	regular.signForm(defaultForm);
	std::cout << defaultForm << std::endl << std::endl;

	Form maxForm("Max", 1, 1);
	regular.signForm(maxForm);
	return 0;
}
