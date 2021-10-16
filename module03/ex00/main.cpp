#include "FlagTrap.hpp"

int main(void)
{
	FlagTrap hi("hh");
	hi.meleeAttack("jj");
	hi.beRepaired(30);
	hi.takeDamage(30);
	hi.rangedAttack("jj");
	hi.vaulthunter_dot_exe("dodo");
	hi.vaulthunter_dot_exe("dodo");
	hi.vaulthunter_dot_exe("dodo");
	hi.vaulthunter_dot_exe("dodo");
	hi.vaulthunter_dot_exe("dodo");

	FlagTrap bye(hi);
	bye.meleeAttack("jj");
	bye.beRepaired(30);
	bye.takeDamage(30);
	bye.beRepaired(30);
	bye.rangedAttack("jj");
	hi.beRepaired(30);
	return 0;
}
