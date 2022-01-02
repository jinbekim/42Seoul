#include "convertor.hpp"

convertor::convertor(const std::string& input):input(input){}
convertor::convertor(const convertor &ref){*this = ref;}
convertor::~convertor(){}
convertor& convertor::operator=(const convertor &ref){input = ref.input;return (*this);}

convertor::operator double() const
{
	try{
		double tmp = std::stod(input);
		return (tmp);
	}
	catch(...){ throw convertor::ImpossibleException(); }
}
convertor::operator float() const
{
	try{
		float tmp = std::stof(input);
		return (tmp);
	}catch(...){ throw convertor::ImpossibleException(); }
}
convertor::operator int() const
{
	try{
		int tmp = std::stoi(input);
		return (tmp);
	}catch(...){ throw convertor::ImpossibleException(); }
}
convertor::operator char() const
{
	int tmp = static_cast<int>(*this);
	if (isprint(tmp))
		return (static_cast<char>(tmp));
	else if (tmp > 255 || tmp < -256)
		throw convertor::ImpossibleException();
	else
		throw convertor::NonDisplayableException();
}

const char* convertor::ImpossibleException::what() const throw()
{
	return ("impossible");
}

const char* convertor::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}
