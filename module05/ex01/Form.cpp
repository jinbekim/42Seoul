#include "Form.hpp"

Form::Form(const std::string &name, const int signgrade, const int exegrade)
	:_name(name), _sign_grade(signgrade), _exec_grade(exegrade)
{
	_signed = 0;
	if (_sign_grade > 150|| _exec_grade > 150)
		throw Form::GradeTooLowException();
	else if (_sign_grade < 1|| _exec_grade < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &ref)
	:_name(ref._name),_sign_grade(ref._sign_grade), _exec_grade(ref._exec_grade)
{
	*this = ref;
	if (_sign_grade > 150|| _exec_grade > 150)
		throw Form::GradeTooLowException();
	else if (_sign_grade < 1|| _exec_grade < 1)
		throw GradeTooHighException();
}

Form::~Form()
{
}

Form& Form::operator=(const Form &ref)
{
	_signed = ref._signed;
	return (*this);
}
std::ostream & operator<<(std::ostream& os, Form &form)
{
	os<<
	"<"<<form.getName()<<">,"
	"<"<<form.getSignGrade()<<">,"
	"<"<<form.getExecGrade()<<">,"
	"<" << std::boolalpha << form.getSigned()<<">";
	return os;
}

bool			Form::canGetSign(const Bureaucrat &bur) const
{
	return (bur.getGrade() > this->_sign_grade);
}

bool	Form::beSigned(const Bureaucrat &bur)
{
	if (canGetSign(bur))
		throw Form::GradeTooLowException();
	this->_signed = true;
	return (this->_signed);
}


const char* Form::GradeTooHighException::what() const throw()
{
	return ("FormException: Grade too High");
}
const char* Form::GradeTooLowException::what() const throw()
{
	return ("FormException: Grade too Low");
}

const std::string& Form::getName(void) const{return (this->_name);}
const unsigned int& Form::getSignGrade(void) const{return (this->_sign_grade);}
const unsigned int& Form::getExecGrade(void) const{return (this->_exec_grade);}
bool				Form::getSigned(void) const{return (this->_signed);}

