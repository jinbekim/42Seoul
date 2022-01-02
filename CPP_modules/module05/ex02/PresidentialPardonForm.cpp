#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	:Form("PresidentialPardon", 25, 5), target(target)
{}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref)
	:Form("PresidentialPardon", 25, 5), target(ref.target)
{}
PresidentialPardonForm::~PresidentialPardonForm()
{}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
	(void)ref;
	return (*this);
}
void		PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw	PresidentialPardonForm::FormNotSignedException();
	if (this->canGetSign(executor))
		throw	PresidentialPardonForm::GradeTooLowException();
	std::cout<<
	this->target << " has been pardoned by Zafod Beeblebrox."
	<< std::endl;
}
