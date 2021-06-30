#include "ZombieEvent.hpp"

const static std::string	g_adjective[6] = {
	"fun", "lovely", "cute", "sexy", "charming", "attractive"
};

const static std::string	g_noun[6] = {
	"body", "one", "cat", "dog", "tiger", "squid"
};

static std::string	genRandomName(){
	int	i, j;

	i = rand() % 6;
	j = rand() % 6;
	return (g_adjective[i] + " " + g_noun[j]);
}

void	ZombieEvent::setZombieType(const std::string &type){
	this->type = type;
}

void	ZombieEvent::randomChump(){
	std::string	randomName = genRandomName();
	Zombie	newOne = Zombie(randomName, this->type);
	newOne.announce();
}

Zombie*	ZombieEvent::newZombie(const std::string &name){
	return (new Zombie(name, this->type));
}
