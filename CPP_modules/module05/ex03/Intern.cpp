#include "Intern.hpp"

Intern::Intern()
{}
Intern::Intern(const Intern &ref)
{
	(void)ref;
}
Intern::~Intern()
{}
Intern& Intern::operator=(const Intern &ref)
{
	(void)ref;
	return (*this);
}

Form *president(const std::string& target)
{
	Form *form = new PresidentialPardonForm(target);
	return (form);
}

Form *robot(const std::string& target)
{
	Form *form = new RobotomyRequestForm(target);
	return (form);
}

Form *shrubbery(const std::string& target)
{
	Form *form = new ShrubberyCreationForm(target);
	return (form);
}

Form*	Intern::makeForm(const std::string &formName, const std::string& target)
{
	static std::string namePool[3] = {"shrubbery", "robotomy", "presidential"};
	Form* (*ft[3])(const std::string&) = {shrubbery, robot, president};

	for (int i = 0; i < 3; ++i){
		if (formName == namePool[i])
			return (ft[i](target));
	}
	throw Intern::InvalidNameException();
}

const char*	Intern::InvalidNameException::what() const throw()
{
	return ("Intern: Exception: InvalidName.");
}
