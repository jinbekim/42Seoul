#ifndef Intern_HPP
# define Intern_HPP

# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern(/* args*/);
		Intern(const Intern &ref);
		~Intern();
		Intern& operator=(const Intern &ref);

		Form*	makeForm(const std::string &formName, const std::string& target);

		class	InvalidNameException:public std::exception{
			public:
				virtual const char*	what() const throw();
		};
};

#endif
