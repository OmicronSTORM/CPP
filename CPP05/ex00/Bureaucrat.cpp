#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150) {
	std::cout << "[Bureaucrat::Bureaucrat]: Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade) {
	std::cout << "[Bureaucrat::Bureaucrat]: Alternate default constructor called" << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {
	std::cout << "[Bureaucrat::Bureaucrat]: Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "[Bureaucrat::~Bureaucrat]: Destructor called" << std::endl;
}

std::string Bureaucrat::getName() const {
	return this->_name;
};

unsigned int Bureaucrat::getGrade() const {
	return this->_grade;
};

void Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
		return;
	}
	else if (this->_grade - 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
		return;
	}
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
		return;
	}
	else if (this->_grade + 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
		return;
	}
	this->_grade++;
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &bureaucrat) {
	return stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
}
