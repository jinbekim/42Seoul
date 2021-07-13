#ifndef span_HPP
# define span_HPP

# include <iostream>
# include <algorithm>
# include <iterator>
# include <set>

class Span
{
	private:
		size_t 				maxSize;
		std::multiset<int>	ms;

		class FullException:public std::exception
		{ public: const char* what() const throw(); };
		class ShortException:public std::exception
		{ public: const char* what() const throw(); };
	public:
		Span(const size_t&	maxSize);
		Span(const Span &ref);
		~Span();
		Span& operator=(const Span &ref);

		size_t	shortestSpan(void) const;
		size_t	longestSpan(void) const;


		void	addNumber(int number);
		template<typename InputIterator> // 정의 선언 분리시 에러, ipp 파일 가능
		void	addNumber(InputIterator begin, InputIterator end)
		{
			if (ms.size() + std::distance(begin, end) > maxSize)
				throw FullException();
			ms.insert(begin, end);
		}

};

#endif
