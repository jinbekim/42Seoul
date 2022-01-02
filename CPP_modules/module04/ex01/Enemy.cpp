#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const &type):HP(hp), Type(type)
{
}


Enemy::Enemy(const Enemy &ref)
{
	Enemy::copy(ref); // *this = ref;
}

Enemy::~Enemy()
{
}

void	Enemy::copy(const Enemy& ref)
{
	this->HP = ref.HP;
	this->Type = ref.Type;
}

Enemy& Enemy::operator=(const Enemy &ref)
{
	Enemy::copy(ref);
	return (*this);
}
std::string const& Enemy::getType() const
{
	return (this->Type);
}
int	Enemy::getHP() const
{
	return (this->HP);
}

void Enemy::takeDamage(int damage)
{
	if (damage < 0)
		return ;
	this->HP -= damage;
	if (this->HP < 0)
		this->HP = 0;
}
