#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	:Form("RobotomyRequest", 72, 45), target(target)
{}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref)
	:Form("RobotomyRequest", 72, 45), target(ref.target)
{}
RobotomyRequestForm::~RobotomyRequestForm()
{}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
	(void)ref;
	return (*this);
}

void		RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw	RobotomyRequestForm::FormNotSignedException();
	if (this->canGetSign(executor))
		throw	RobotomyRequestForm::GradeTooLowException();
	std::cout << "* VRRRRR BZZZZZZ VRRRRRR *" << std::endl;
	if (rand() % 100 < 50)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << " robotomization is a failure" << std::endl;

}
