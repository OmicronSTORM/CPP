#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm_Default", 25, 5) {
	std::cout << "[PresidentialPardonForm::PresidentialPardonForm]: Default constructor called" << std::endl;
	this->_target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm_" + target, 25, 5) {
	std::cout << "[PresidentialPardonForm::PresidentialPardonForm]: Alternative constructor called" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other) {
	std::cout << "[PresidentialPardonForm::PresidentialPardonForm]: Copy constructor called" << std::endl;
	this->_target = other._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
	std::cout << "[PresidentialPardonForm::operator=]: Copy assignement operator called" << std::endl;
	this->_target = other._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "[PresidentialPardonForm::~PresidentialPardonForm]: Destructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
	return this->_target;
}

unsigned int PresidentialPardonForm::getSigningGrade() const {
	return this->_signingGrade;
}

unsigned int PresidentialPardonForm::getExecutingGrade() const {
	return this->_executingGrade;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->isSigned()) {
		throw PresidentialPardonForm::FormNotSignedException();
		return;
	}
	else if (executor.getGrade() > this->getExecutingGrade()) {
		throw PresidentialPardonForm::GradeTooLowException();
		return;
	}

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
