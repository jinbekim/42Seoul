#ifndef Form_HPP
# define Form_HPP

# include "Bureaucrat.hpp"
# include <iomanip>

class Bureaucrat ;

class Form
{
	private:
		Form();
		const std::string	_name;
		const unsigned int	_sign_grade;
		const unsigned int	_exec_grade;
		bool				_signed;
	public:
		Form(const std::string &name, const int signgrade, const int exegrade);
		Form(const Form &ref);
		virtual ~Form();
		Form& operator=(const Form &ref);

		const std::string&	getName(void) const;
		const unsigned int&	getSignGrade(void) const;
		const unsigned int&	getExecGrade(void) const;
		bool				getSigned(void) const;
		bool				canGetSign(const Bureaucrat &) const;
		bool				beSigned(const Bureaucrat &);

		virtual void		execute(Bureaucrat const & executor) const = 0;


		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class FileCannotOpenException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};
std::ostream & operator<<(std::ostream&, Form &);

#endif
