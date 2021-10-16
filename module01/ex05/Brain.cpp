#include "Brain.hpp"

Brain::Brain(const std::string &name):name(name)
{}

std::string	Brain::identify() const {
	std::stringstream	stream;
	const long	test = (long)this;

	stream << "0x" << std::uppercase << std::hex << test;
	return (stream.str());
}
