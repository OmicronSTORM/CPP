#pragma once
#include "Bureaucrat.hpp"
#include <exception>

class AForm {
public:
	AForm();
	AForm(std::string name, unsigned int signingGrade, unsigned int executingGrade);
	AForm(AForm const &other);
	AForm &operator=(AForm const &other);
	virtual ~AForm();

	class GradeTooHighException : public std::exception {
		const char *what() const throw() {
			return "The grade is too high";
		}
	};

	class GradeTooLowException : public std::exception {
		const char *what() const throw() {
			return "The grade is too low";
		}
	};

	class FormNotSignedException : public std::exception {
		const char *what() const throw() {
			return "Form is not signed";
		}
	};

public:
	void beSigned(Bureaucrat const &bureaucrat);
	bool isSigned() const;
	virtual unsigned int getSigningGrade() const;
	virtual unsigned int getExecutingGrade() const;
	std::string getName() const;
	virtual void execute(Bureaucrat const & executor) const = 0;
	virtual std::string getTarget() const = 0;
private:
	const std::string _name;
	bool _signed;
	const unsigned int _signingGrade;
	const unsigned int _executingGrade;
};

std::ostream &operator<<(std::ostream &stream, AForm const &form); 
