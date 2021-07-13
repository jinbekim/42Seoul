#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat francis("Francis", 100);
	std::cout << francis << std::endl;
	francis.incrementGrade();
	std::cout << francis << std::endl;
	francis.decrementGrade();
	std::cout << francis << std::endl;

	try
	{
		Bureaucrat jack("Jack", 0);
		std::cout << jack << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException const &e)
	{
		std::cerr << e.what() << std::endl;
	}
		//만약 위아래 형식이 같았다면? 그래서 미리 만들어둔 예외 클래스를 상속해서 만들고
		// 오버라이드 해서 사용함.
	try
	{
		Bureaucrat jack("Jack", 1000);
		std::cout << jack << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException const &e)
	{
		std::cerr << e.print() << std::endl;
	}

	try
	{
		Bureaucrat jack("Jack", 1);
		std::cout << jack << std::endl;
		jack.incrementGrade();
		std::cout << jack << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat jack("Jack", 150);
		std::cout << jack << std::endl;
		jack.decrementGrade();
		std::cout << jack << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
