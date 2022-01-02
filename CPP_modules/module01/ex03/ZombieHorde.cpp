#include "ZombieHorde.hpp"

static const std::string	g_adjective[6] = {
	"fun", "lovely", "cute", "sexy", "charming", "attractive"
};

static const std::string	g_noun[6] = {
	"body", "one", "cat", "dog", "tiger", "squid"
};

inline static std::string	genRandomName(int i, int j){return (g_adjective[i] + " " + g_noun[j]);}

inline static std::string	genRandomType(int i){return (g_noun[i]);}

ZombieHorde::ZombieHorde(int N)
	:num(N)
{
	std::string	random_name;
	std::string	random_type;
	std::random_device	rd;
	std::mt19937	gen(rd());
	std::uniform_int_distribution<int>	dis(0, 5);

	horde = new Zombie[N]();
	for (int i = 0 ; i < num ; ++i){
		srand(time(NULL));
		random_name = genRandomName(dis(gen), dis(gen));
		random_type = genRandomType(dis(gen));
		horde[i].SetNameType(random_name, random_type);
	}
}

ZombieHorde::~ZombieHorde(){
	delete []horde;
	std::cout << "bye" << std::endl;
}

void	ZombieHorde::announce(){
	for (int i = 0; i < num ; ++i){
		horde[i].announce();
	}
}
