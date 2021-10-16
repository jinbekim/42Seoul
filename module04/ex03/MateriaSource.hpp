#ifndef MateriaSource_HPP
# define MateriaSource_HPP

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria*	src[4];
	public:
		MateriaSource(/* args*/);
		MateriaSource(const MateriaSource &ref);
		virtual ~MateriaSource();
		MateriaSource& operator=(const MateriaSource &ref);

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
};

#endif
