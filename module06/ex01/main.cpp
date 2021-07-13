#include "Data.hpp"
#include <iostream>

int main(void)
{
	Data* data = new Data;
	data->strData = strdup("data");
	data->intData = 42;
	Data* data2;
	data2 = deserialize(serialize(data));

	std::cout << data2->intData << std::endl;
	std::cout << data2->strData << std::endl;

	delete data2;
	delete data->strData;
	delete data;
	return 0;
}
