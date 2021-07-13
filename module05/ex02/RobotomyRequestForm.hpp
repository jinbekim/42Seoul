#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include "Form.hpp"

class RobotomyRequestForm: public Form
{
	private:
		const std::string target;
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &ref);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm &ref);

		virtual void		execute(Bureaucrat const & executor) const;
};

#endif
