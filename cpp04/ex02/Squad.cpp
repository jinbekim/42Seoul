#include "Squad.hpp"

Squad::Squad():Num(0), Unit(NULL)
{
}

Squad::Squad(const Squad &ref):Num(0), Unit(NULL)
{
	for (int i = 0; i < ref.getCount(); ++i)
	this->push(ref.getUnit(i)->clone());
}

Squad::~Squad()
{
	if (!this->Num)
		return ;
	for (int i = 0; i < this->Num; ++i)
		delete this->Unit[i];
	delete[] this->Unit;
}

Squad& Squad::operator=(const Squad &ref)
{
	if (this->Unit)
	{
		for(int i = 0; i < this->Num ; ++i)
			delete this->Unit[i];
		delete[] this->Unit;
		this->Unit = NULL;
	}
	this->Num = 0;
	for (int i = 0; i < ref.getCount(); ++i)
		this->push(ref.getUnit(i)->clone());
	return (*this);
}

int	Squad::getCount(void) const
{
	return (this->Num);
}

ISpaceMarine* Squad::getUnit(int N) const
{
	if (this->Num <= N || N < 0)
		return (NULL);
	return (this->Unit[N]);
}

int Squad::push(ISpaceMarine* new_unit)
{
	if (new_unit == NULL)
		return this->Num;
	if (this->Unit)
	{
		for (int i = 0; i < this->Num; ++i)
			if (this->Unit[i] == new_unit)
				return (this->Num);
		ISpaceMarine **tmp = new ISpaceMarine*[this->Num + 1];
		for (int i = 0; i < this->Num; ++i)
			tmp[i] = this->Unit[i];
		delete[] this->Unit;
		tmp[this->Num] = new_unit;
		this->Unit = tmp;
		this->Num++;
	}
	else
	{
		this->Unit = new ISpaceMarine*[1];
		this->Unit[0] = new_unit;
		this->Num = 1;
	}
	return this->Num;
}
