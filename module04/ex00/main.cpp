#include "Sorcerer.hpp"

int	main(void)
{
	Sorcerer robert("Robert", "the Magnificent");

	Victim jim("Jimmy");
	Peon joe("Joe");

	std::cout << robert << jim << joe;

	robert.polymorph(jim);
	jim.getPolymorphed();
	robert.polymorph(joe);
	joe.getPolymorphed();
	std::cout<< "-------------" << std::endl;

	Victim* goblin = new Goblin("gongyoo");
	goblin->print_intro();
	robert.polymorph(*goblin);
	goblin->getPolymorphed();

	delete goblin;
	std::cout<< "-------------" << std::endl;
	Goblin jj3("jj3");
	Goblin jj("doo");
	jj = jj3;

	std::cout<< "-------------" << std::endl;
	std::cout<<
	jj3.get_name()
	<< std::endl;
	std::cout<<
	jj.get_name()
	<< std::endl;
	std::cout<< "-------------" << std::endl;

	return 0;
}
