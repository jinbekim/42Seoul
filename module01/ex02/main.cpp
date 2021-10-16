#include "ZombieEvent.hpp"

int	main(void){
	ZombieEvent event;
	Zombie		*body;

	event.setZombieType("water");
	body = event.newZombie("jinbekim");
	body->announce();
	delete body;
	srand(time(NULL));
	event.setZombieType("fire");
	event.randomChump();
	event.setZombieType("tree");
	event.randomChump();
}
