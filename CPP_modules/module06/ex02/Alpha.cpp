#include "Alpha.hpp"

A::A(){}
A::A(const A &ref){*this = ref;}
A::~A(){}
A& A::operator=(const A &ref)
{
	(void)ref;
	return (*this);
}

B::B(){}
B::B(const B &ref){*this = ref;}
B::~B(){}
B& B::operator=(const B &ref)
{
	(void)ref;
	return (*this);
}

C::C(){}
C::C(const C &ref){*this = ref;}
C::~C(){}
C& C::operator=(const C &ref)
{
	(void)ref;
	return (*this);
}
