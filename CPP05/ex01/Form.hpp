#pragma once
#include "Bureaucrat.hpp"

class Form {
public:
	Form();
	Form(std::string name, unsigned int signingGrade, unsigned int executingGrade);
	Form(Form const &other);
	Form &operator=(Form const &other);
	~Form();

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

public:
	void beSigned(Bureaucrat const &bureaucrat);
	bool isSigned() const;
	unsigned int getSigningGrade() const;
	unsigned int getExecutingGrade() const;
	std::string getName() const; 
private:
	const std::string _name;
	bool _signed;
	const unsigned int _signingGrade;
	const unsigned int _executingGrade;
};

std::ostream &operator<<(std::ostream &stream, Form const &form); 
