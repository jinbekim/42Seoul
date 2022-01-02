#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern maker;
	Bureaucrat super("super", 1);

	try{
		Form* robo = maker.makeForm("robotomy", "target");
		super.signForm(*robo);
		robo->execute(super);
		delete robo;
		robo = maker.makeForm("shrubbery", "target");
		super.signForm(*robo);
		robo->execute(super);
		delete robo;
		robo = maker.makeForm("presidential", "target");
		super.signForm(*robo);
		robo->execute(super);
		delete robo;
		robo = maker.makeForm("pres", "target");
		super.signForm(*robo);
		robo->execute(super);
		delete robo;
	}catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
