#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <exception>

int main(int argc, const char **argv) {
	AForm *form;
	Bureaucrat god = Bureaucrat("GOD", 1);
	Intern worker;

	if (argc != 3)
		return 1;
	form = worker.makeForm(argv[1], argv[2]);
	if (!form)
		return 1;

	std::cout << *form << std::endl;
	try {
		god.signForm(*form);
		god.executeForm(*form);
	} catch (std::exception &e) {
		std::cout << "Failed to sign or execute form: " << std::endl;
	}
	delete form;
	return 0;
}
