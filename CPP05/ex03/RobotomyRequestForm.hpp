#pragma once
#include "AForm.hpp"
#include <exception>

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
	~RobotomyRequestForm();

public:
	std::string getTarget() const;
	unsigned int getSigningGrade() const;
	unsigned int getExecutingGrade() const;
	void execute(Bureaucrat const & executor) const;
private:
	std::string _target;
	static const unsigned int _signingGrade = 72;
	static const unsigned int _executingGrade = 45;
};
