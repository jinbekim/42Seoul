# include "Alpha.hpp"
# include "Base.hpp"
# include <iostream>

Base * generate(void)
{
	Base* retPtr;
	switch (rand() % 3)
	{
	case Aclass:
		retPtr = new A();
		break;
	case Bclass:
		retPtr = new B();
		break;
	case Cclass:
		retPtr = new C();
		break;
	}
	return (retPtr);
}
void identify(Base* p)
{
	void* retPtr;

	if ((retPtr = dynamic_cast<A*>(p)))
		std::cout << "A" << std::endl;
	else if ((retPtr = dynamic_cast<B*>(p)))
		std::cout << "B" << std::endl;
	else if ((retPtr = dynamic_cast<C*>(p)))
		std::cout << "C" << std::endl;
}
void identify(Base& p)
{
	identify(&p);
}

int main(void)
{
	srand(time(nullptr));

	Base* ptr = generate();
	identify(ptr);
	identify(*ptr);

	delete ptr;
	return 0;
}
