#ifndef A_HPP
# define A_HPP

# include "Base.hpp"

enum	e_alpha{
	Aclass,
	Bclass,
	Cclass
};

class A : public Base
{
	private:
		/* data */
	public:
		A(/* args*/);
		A(const A &ref);
		~A();
		A& operator=(const A &ref);
};
class B : public Base
{
	private:
		/* data */
	public:
		B(/* args*/);
		B(const B &ref);
		~B();
		B& operator=(const B &ref);
};
class C : public Base
{
	private:
		/* data */
	public:
		C(/* args*/);
		C(const C &ref);
		~C();
		C& operator=(const C &ref);
};

#endif
