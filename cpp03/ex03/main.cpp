#include "NinjaTrap.hpp"

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

	std::cout << "-----" << std::endl;
	ClapTrap jojo("jojo");
	NinjaTrap nini("nini");
	nini.beRepaired(30);
	nini.takeDamage(30);
	nini.beRepaired(30);
	nini.meleeAttack("jj");
	nini.rangedAttack("jj");
	nini.ninjaShoebox(nini);
	nini.ninjaShoebox(toto);
	nini.ninjaShoebox(hi);
	nini.ninjaShoebox(jojo);
	std::cout << "-----" << std::endl;

	return (0);
}
