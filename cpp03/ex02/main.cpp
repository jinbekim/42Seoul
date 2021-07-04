#include "FlagTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	srand(time(0));

	FlagTrap hi("hh");
	hi.meleeAttack("jj");
	hi.beRepaired(30);
	hi.takeDamage(30);
	hi.beRepaired(30);
	hi.rangedAttack("jj");
	hi.vaulthunter_dot_exe("dodo");
	hi.vaulthunter_dot_exe("dodo");
	hi.vaulthunter_dot_exe("dodo");
	hi.vaulthunter_dot_exe("dodo");
	hi.vaulthunter_dot_exe("dodo");
	std::cout << "-----" << std::endl;

	ScavTrap toto("toto");
	toto.beRepaired(30);
	toto.takeDamage(30);
	toto.beRepaired(30);
	toto.meleeAttack("jj");
	toto.rangedAttack("jj");
	toto.challengeNewcomer();
	toto.challengeNewcomer();
	toto.challengeNewcomer();
	toto.challengeNewcomer();

	return (0);
}
