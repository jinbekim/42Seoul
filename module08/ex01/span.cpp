#include "span.hpp"

Span::Span(const size_t& maxSize):maxSize(maxSize)
{
}

Span::Span(const Span &ref)
{
	*this = ref;
}

Span::~Span()
{
	ms.clear();
}

Span& Span::operator=(const Span &ref)
{
	maxSize = ref.maxSize;
	ms.clear();
	ms = ref.ms;
	return (*this);
}

size_t	Span::shortestSpan(void) const
{
	if (ms.size() < 2)
		throw ShortException();
	std::multiset<int>::iterator	it = ms.begin();
	std::multiset<int>::iterator	itNext = ++ms.begin();
	std::set<int> sub;
	for(;itNext != ms.end(); ++it, ++itNext)
		sub.insert(*itNext - *it);
	int ret = *sub.begin();
	sub.clear();
	return (ret);
}
size_t	Span::longestSpan(void) const
{
	if (ms.size() < 2)
		throw ShortException();
	return (*--ms.end() - *ms.begin());
}

void	Span::addNumber(int number)
{
	if (maxSize == ms.size())
		throw FullException();
	ms.insert(number);
}

const char* Span::FullException::what() const throw()
{
	return ("No more numbers");
}
const char* Span::ShortException::what() const throw()
{
	return ("Add more numbers!");
}
