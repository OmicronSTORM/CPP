#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm_Default", 145, 137) {
	std::cout << "[ShrubberyCreationForm::ShrubberyCreationForm]: Default constructor called" << std::endl;
	this->_target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm_"+target, 145, 137){
	std::cout << "[ShrubberyCreationForm::ShrubberyCreationForm]: Alternative constructor called" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other) {
	std::cout << "[ShrubberyCreationForm::ShrubberyCreationForm]: Copy constructor called" << std::endl;
	this->_target = other._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
	std::cout << "[ShrubberyCreationForm::operator=]: Copy assignement operator called" << std::endl;
	this->_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "[ShrubberyCreationForm::~ShrubberyCreationForm]: Destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

unsigned int ShrubberyCreationForm::getSigningGrade() const {
	return this->_signingGrade;
}

unsigned int ShrubberyCreationForm::getExecutingGrade() const {
	return this->_executingGrade;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	std::fstream file;

	if (!this->isSigned()) {
		throw ShrubberyCreationForm::FormNotSignedException();
		return;
	}
	else if (executor.getGrade() > this->getExecutingGrade()) {
		throw ShrubberyCreationForm::GradeTooLowException();
		return;
	}

	std::string filename = this->getTarget() + "_shrubbery";
	file.open(filename.c_str(), std::fstream::app);
	if (!file.is_open()) {
		throw ShrubberyCreationForm::FileErrorException();
		return;
	}
	std::string asciiTree =
"                                                         .\n"
"                                              .         ;  \n"
"                 .              .              ;%     ;;   \n"
"                   ,           ,                :;%  %;   \n"
"                    :         ;                   :;%;'     .,   \n"
"           ,.        %;     %;            ;        %;'    ,;\n"
"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
"              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
"                `%;.     ;%;     %;'         `;%%;.%;'\n"
"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
"                    `:%;.  :;bd%;          %;@%;'\n"
"                      `@%:.  :;%.         ;@@%;'   \n"
"                        `@%.  `;@%.      ;@@%;         \n"
"                          `@%%. `@%%    ;@@%;        \n"
"                            ;@%. :@%%  %@@%;       \n"
"                              %@bd%%%bd%%:;     \n"
"                                #@%%%%%:;;\n"
"                                %@@%%%::;\n"
"                                %@@@%(o);  . '         \n"
"                                %@@@o%;:(.,'         \n"
"                            `.. %@@@o%::;         \n"
"                               `)@@@o%::;         \n"
"                                %@@(o)::;        \n"
"                               .%@@@@%::;         \n"
"                               ;%@@@@%::;.          \n"
"                              ;%@@@@%%:;;;. \n"
"                          ...;%@@@@@%%:;;;;,..    ";
	file.write(asciiTree.c_str(), asciiTree.size());
	file.close();
}
