#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

# include <string>
# include <iostream>
# include "Form.hpp"
class Form ;

class Bureaucrat
{
	private:
		Bureaucrat();

		const std::string _name;
		unsigned int	_grade;
	public:
		Bureaucrat(std::string const &name, unsigned int grade);
		Bureaucrat(const Bureaucrat &ref);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat &ref);
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const std::string print() const;
		};

		const std::string& getName(void) const;
		const unsigned int& getGrade(void) const;
		void	incrementGrade(void);
		void	decrementGrade(void);

		void	signForm(Form&) const;
		void	executeForm(Form const & form);

};
std::ostream & operator<<(std::ostream&, Bureaucrat &);

#endif
