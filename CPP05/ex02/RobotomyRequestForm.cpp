#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm_Default", 72, 45) {
	std::cout << "[RobotomyRequestForm::RobotomyRequestForm]: Default constructor called" << std::endl;
	this->_target = "Default";
	srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm_"+target, 72, 45) {
	std::cout << "[RobotomyRequestForm::RobotomyRequestForm]: Alternative constructor called" << std::endl;
	this->_target = target;
	srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other) {
	std::cout << "[RobotomyRequestForm::RobotomyRequestForm]: Copy constructor called" << std::endl;
	this->_target = other._target;
	srand(time(0));
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
	std::cout << "[RobotomyRequestForm::operator=]: Copy assignement operator called" << std::endl;
	this->_target = other._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "[RobotomyRequestForm::~RobotomyRequestForm]: Destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
}

unsigned int RobotomyRequestForm::getSigningGrade() const {
	return this->_signingGrade;
}

unsigned int RobotomyRequestForm::getExecutingGrade() const {
	return this->_executingGrade;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->isSigned()) {
		throw RobotomyRequestForm::FormNotSignedException();
		return;
	}
	else if (executor.getGrade() > this->getExecutingGrade()) {
		throw RobotomyRequestForm::GradeTooLowException();
		return;
	}

	std::cout << "* DRILLING NOISES * Brrrrrrrrr... Drrrrrrr... *" << std::endl;
	bool shouldExecute = (bool)(rand() % 2);
	if (!shouldExecute) {
		std::cout << this->getTarget() << "'s robotomy failed" << std::endl;
		return;
	}
	std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
}
