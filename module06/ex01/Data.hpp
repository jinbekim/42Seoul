#ifndef Data_HPP
# define Data_HPP

# include <string>
# include <iostream>


typedef struct s_data
{
	int		intData;
	char*	strData;
}Data;

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif
