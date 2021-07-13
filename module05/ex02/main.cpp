#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	srand(time(NULL));

	Bureaucrat supervisor("Supervisor", 1);
	std::cout << supervisor << std::endl;
	Bureaucrat francis("Francis", 25);
	std::cout << francis << std::endl;

	Form *shrub = new ShrubberyCreationForm("home");
	std::cout << *shrub << std::endl;
	shrub->beSigned(supervisor);
	shrub->execute(francis);
	std::cout << "1---1" << std::endl;

	Form *pres = new PresidentialPardonForm("Francis");
	std::cout << *pres << std::endl;
	supervisor.signForm(*pres);
	pres->execute(supervisor);
	std::cout << "2---2" << std::endl;

	Form *robot = new RobotomyRequestForm("Bender");
	std::cout << *robot << std::endl;
	robot->beSigned(supervisor);
	robot->execute(francis);
	francis.executeForm(*robot);
	francis.executeForm(*robot);

	std::cout << "3---3" << std::endl;

	try
	{
		francis.executeForm(*pres);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "4---4" << std::endl;

	try
	{
		RobotomyRequestForm robot = RobotomyRequestForm("Bender");
		std::cout << robot << std::endl;
		robot.execute(supervisor);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "5---5" << std::endl;

	try
	{
		PresidentialPardonForm pres = PresidentialPardonForm("Francis");
		std::cout << pres << std::endl;
		supervisor.signForm(pres);
		pres.execute(francis);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "6---6" << std::endl;

	try
	{
		PresidentialPardonForm pres = PresidentialPardonForm("Francis");
		std::cout << pres << std::endl;
		supervisor.signForm(pres);
		francis.executeForm(pres);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete shrub;
	delete pres;
	delete robot;

	return (0);
}
