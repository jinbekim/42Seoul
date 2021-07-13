#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include "Form.hpp"

class PresidentialPardonForm:public Form
{
	private:
		const std::string	target;
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &ref);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm &ref);

		virtual void		execute(Bureaucrat const & executor) const;
};

#endif
