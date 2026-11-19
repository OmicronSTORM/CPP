#include "Bureaucrat.hpp"
#include <exception>

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

	Bureaucrat moon("To the moon", 150);
	try {
		for (int i = 0; i < 200; i++) {
			moon.incrementGrade();
		}
	}
	catch (std::exception &e ) {
		std::cout << "Couldn't reach the moon: " << e.what() << std::endl;
	}

	Bureaucrat ground("To the ground", 1);
	try {
		for (int i = 0; i < 200; i++) {
			moon.decrementGrade();
		}
	}
	catch (std::exception &e ) {
		std::cout << "Couldn't reach the ground: " << e.what() << std::endl;
	}	
	return 0;
}
