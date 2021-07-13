#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	private:
		Bureaucrat();

		const std::string _name;
		unsigned int	_grade; // 1~ 150
	public:
		Bureaucrat(std::string const &name, unsigned int grade);
		Bureaucrat(const Bureaucrat &ref);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat &ref);
		// 중첩클래스
		// 캡슐화, 접근제어, 내부클래스에서 외부클래스에 쉽게 접근.
		// 위 아래 함수명 다르게 한 이유. 메인문에서 확인.
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw(); // throw() === noexcept
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const std::string print() const;
		};

		const std::string& getName(void) const;
		const unsigned int& getGrade(void) const;
		void	incrementGrade(void);
		void	decrementGrade(void);

};


std::ostream & operator<<(std::ostream&, Bureaucrat &);

#endif
