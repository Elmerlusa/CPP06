#include <iostream>

#include "Data.hpp"

uintptr_t	serialize(Data* ptr);
Data*	deserialize(uintptr_t raw);
void	printData(Data* d);

int	main(void)
{
	Data*		d = new Data();
	uintptr_t	p;
	Data*		result = NULL;

	d->name = "El Nano";
	d->age = 42;
	printData(d);
	p = serialize(NULL);
	result = deserialize(p);
	std::cout << "RESULT (uintptr_t = " << p << "): ";
	printData(result);
	delete d;
	return 0;
}

uintptr_t	serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

void	printData(Data* d)
{
	if (d == NULL)
		std::cout << "NULL" << std::endl;
	else
		std::cout << "Data(" << d->name << ", " << d->age << ")" << std::endl;
}
