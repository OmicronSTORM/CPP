#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _signed(false), _signingGrade(150), _executingGrade(150) {
	std::cout << "[AForm::AForm]: Default constructor called" << std::endl;
}

AForm::AForm(std::string name, unsigned int signingGrade, unsigned int executingGrade) : _name(name) ,_signed(false), _signingGrade(signingGrade), _executingGrade(executingGrade) {
	std::cout << "[AForm::AForm]: Alternate constructor called" << std::endl;
	if (_signingGrade > 150 || _executingGrade > 150) {
		throw AForm::GradeTooLowException();
	}
	else if (_signingGrade < 1 || _executingGrade < 1) {
		throw AForm::GradeTooHighException();
	}
}

AForm::AForm(AForm const &other) : _name(other._name), _signed(false), _signingGrade(other._signingGrade), _executingGrade(other._executingGrade) {
	std::cout << "[AForm::AForm]: Copy constructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &other) {
	std::cout << "[AForm::operator=]: Copy assignement operator called" << std::endl;
	this->_signed = other._signed;
	return *this;
}

AForm::~AForm() {
	std::cout << "[AForm::~AForm]: Destructor called" << std::endl;
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->_signingGrade)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

std::string AForm::getName() const {
	return this->_name;
}

bool AForm::isSigned() const {
	return this->_signed;
}

unsigned int AForm::getSigningGrade() const {
	return this->_signingGrade;
}

unsigned int AForm::getExecutingGrade() const {
	return this->_executingGrade;
}

std::ostream &operator<<(std::ostream &stream, AForm const &form) {
	return stream << form.getName() << ", form signed " << form.isSigned()
		<< ", signing grade " << form.getSigningGrade()
		<< ", executing grade " << form.getExecutingGrade();
}
