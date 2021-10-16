#ifndef Enemy_HPP
# define Enemy_HPP

# include <iostream>
# include <string>

class Enemy
{
	protected:
		Enemy();

		int	HP;
		std::string 	Type;
		void	copy(const Enemy &);
	public:
		Enemy(int, std::string const &);
		Enemy(const Enemy &);
		virtual ~Enemy();
		Enemy& operator=(const Enemy &);

		std::string const& getType() const;
		int	getHP() const;

		virtual void takeDamage(int);
};

#endif
