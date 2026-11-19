#pragma once

#include <exception>
#include <string>
#include <iostream>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat &operator=(Bureaucrat const &other);
	~Bureaucrat();

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
	std::string getName() const;
	unsigned int getGrade() const;
	void incrementGrade();
	void decrementGrade();
private:
	const std::string _name;
	unsigned int _grade;
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &bureaucrat);
