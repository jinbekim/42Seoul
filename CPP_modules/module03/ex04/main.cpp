#include "SuperTrap.hpp"

int main()
{
	srand(time(0));

	// FlagTrap hi("hh");
	// hi.meleeAttack("jj");
	// hi.beRepaired(30);
	// hi.takeDamage(30);
	// hi.beRepaired(30);
	// hi.rangedAttack("jj");
	// hi.vaulthunter_dot_exe("dodo");
	// hi.vaulthunter_dot_exe("dodo");
	// hi.vaulthunter_dot_exe("dodo");
	// hi.vaulthunter_dot_exe("dodo");
	// hi.vaulthunter_dot_exe("dodo");
	// std::cout << "-----" << std::endl;

	// ScavTrap toto("toto");
	// toto.beRepaired(30);
	// toto.takeDamage(30);
	// toto.beRepaired(30);
	// toto.meleeAttack("jj");
	// toto.rangedAttack("jj");
	// toto.challengeNewcomer();
	// toto.challengeNewcomer();
	// toto.challengeNewcomer();
	// toto.challengeNewcomer();

	// std::cout << "-----" << std::endl;
	// ClapTrap jojo("jojo");
	NinjaTrap nini("nini");
	// std::cout << "-----" << std::endl;
	// nini.beRepaired(30);
	// nini.takeDamage(150);
	// nini.beRepaired(30);
	// nini.meleeAttack("jj");
	// nini.rangedAttack("jj");
	// std::cout << "-----" << std::endl;
	// nini.ninjaShoebox(nini);
	// nini.ninjaShoebox(toto);
	// nini.ninjaShoebox(hi);
	// nini.ninjaShoebox(jojo);


	std::cout << "-----" << std::endl;
	SuperTrap	koko("koko");
	koko.beRepaired(30);
	koko.takeDamage(30);
	koko.beRepaired(30);
	koko.meleeAttack("jj");
	koko.rangedAttack("jj");
	std::cout << "-----" << std::endl;
	std::cout << "-----" << std::endl;
	koko.vaulthunter_dot_exe("dodo");
	koko.ninjaShoebox(nini);




	std::cout << "-----" << std::endl;

	return (0);
}
