#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

# include <iostream>
# include <string>

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
				virtual const char* what() const throw();
		};

		const std::string& getName(void) const;
		const unsigned int& getGrade(void) const;
		void	incrementGrade(void);
		void	decrementGrade(void);

};


std::ostream & operator<<(std::ostream&, Bureaucrat &);

#endif
