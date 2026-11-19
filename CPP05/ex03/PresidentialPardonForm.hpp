#pragma once
#include "AForm.hpp"
#include <exception>

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
	~PresidentialPardonForm();
public:
	std::string getTarget() const;
	unsigned int getSigningGrade() const;
	unsigned int getExecutingGrade() const;
	void execute(Bureaucrat const & executor) const;
private:
	std::string _target;
	static const unsigned int _signingGrade = 25;
	static const unsigned int _executingGrade = 5;
};
