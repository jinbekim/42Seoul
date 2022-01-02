#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const & name, unsigned int grade)
	:_name(name), _grade(grade)
{
	if (_grade > 150)
		throw GradeTooLowException();
	else if (_grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref)
	:_name(ref._name),_grade(ref._grade)
{
	if (_grade > 150)
		throw GradeTooLowException();
	else if (_grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &ref)
{
	this->_grade = ref._grade;
	return (*this);
}

std::ostream & operator<<(std::ostream& os, Bureaucrat &bur)
{
	os<< "<" << bur.getName() << ">, bureaucrat grade <" << bur.getGrade() << ">.";
	return (os);
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return ("BureaucratException: Grade too High");
}
const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return ("BureaucratException: Grade too Low");
}

const std::string& Bureaucrat::getName(void) const
{
	return (this->_name);
}
const unsigned int& Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}
void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}
void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}
