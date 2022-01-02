#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0 ; i < 4; ++i)
		this->src[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &ref)
{
	*this = ref;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0 ; i < 4 ; ++i){
		if (this->src[i] != nullptr)
		{
			delete this->src[i];
			this->src[i] = nullptr;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &ref)
{
	for (int i = 0 ; i < 4 ; ++i){
		this->src[i] = ref.src[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4 ; ++i){
		if (this->src[i] == nullptr)
		{
			this->src[i] = materia;
			break ;
		}
	}
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0 ; i < 4 ; ++i){
		if (this->src[i] != nullptr)
			if (this->src[i]->getType() == type)
				return (this->src[i]->clone());
	}
	return (nullptr);
}
