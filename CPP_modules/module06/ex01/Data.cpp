#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	int len = strlen(ptr->strData);
	char* retPtr = new char[sizeof(char) * len + sizeof(int)];

	*(reinterpret_cast<int*>(retPtr)) = ptr->intData;
	for(int i = 0; i < len; ++i)
		*(retPtr + sizeof(int) + i) = ptr->strData[i];
	return (reinterpret_cast<uintptr_t>(retPtr));
}

Data* deserialize(uintptr_t raw)
{
	Data* retPtr = new Data;
	char* rawData = reinterpret_cast<char*>(raw);
	retPtr->intData = *reinterpret_cast<int*>(rawData);
	int len = 0;

	while ((rawData + 4)[len])
		len++;
	retPtr->strData = new char[len + 1];
	for (int j = 0; j < len + 1; ++j){
		retPtr->strData[j] = *(rawData + 4 + j);
	}
	return (retPtr);
}
