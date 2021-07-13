#ifndef convertor_HPP
# define convertor_HPP

# include <string>
# include <iostream>
# include <iomanip>

class convertor
{
	private:
		convertor();

		std::string	input;
	public:
		convertor(const std::string& input);
		convertor(const convertor &ref);
		~convertor();
		convertor& operator=(const convertor &ref);

		operator	int()		const;
		operator	char()		const;
		operator	float()		const;
		operator	double()	const;

		class ImpossibleException:public std::exception
		{
			public:
				const char*	what() const throw();
		};
		class NonDisplayableException:public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

#endif
