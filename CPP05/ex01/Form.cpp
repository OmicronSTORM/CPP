#include "Form.hpp"

Form::Form() : _name("Form"), _signed(false), _signingGrade(150), _executingGrade(150) {
	std::cout << "[Form::Form]: Default constructor called" << std::endl;
}

Form::Form(std::string name, unsigned int signingGrade, unsigned int executingGrade) : _name(name) ,_signed(false), _signingGrade(signingGrade), _executingGrade(executingGrade) {
	std::cout << "[Form::Form]: Alternate constructor called" << std::endl;
	if (_signingGrade > 150 || _executingGrade > 150) {
		throw Form::GradeTooLowException();
	}
	else if (_signingGrade < 1 || _executingGrade < 1) {
		throw Form::GradeTooHighException();
	}
}

Form::Form(Form const &other) : _name(other._name), _signed(false), _signingGrade(other._signingGrade), _executingGrade(other._executingGrade) {
	std::cout << "[Form::Form]: Copy constructor called" << std::endl;
}

Form &Form::operator=(Form const &other) {
	std::cout << "[Form::operator=]: Copy assignement operator called" << std::endl;
	this->_signed = other._signed;
	return *this;
}

Form::~Form() {
	std::cout << "[Form::~Form]: Destructor called" << std::endl;
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->_signingGrade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::string Form::getName() const {
	return this->_name;
}

bool Form::isSigned() const {
	return this->_signed;
}

unsigned int Form::getSigningGrade() const {
	return this->_signingGrade;
}

unsigned int Form::getExecutingGrade() const {
	return this->_executingGrade;
}

std::ostream &operator<<(std::ostream &stream, Form const &form) {
	return stream << form.getName() << ", form signed " << form.isSigned()
		<< ", signing grade " << form.getSigningGrade()
		<< ", executing grade " << form.getExecutingGrade();
}
