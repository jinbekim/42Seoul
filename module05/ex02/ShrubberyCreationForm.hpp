#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm: public Form
{
	private:
		ShrubberyCreationForm();
		const std::string	target;
		static std::string	tree;

	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &ref);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &ref);

		void	execute(Bureaucrat const & executor) const;

};

#endif
