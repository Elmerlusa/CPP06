#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void);
void	identify(Base *p);

int	main(void)
{
	Base*	x = generate();
	
	identify(x);
	delete x;
	return 0;
}

Base*	generate(void)
{
	std::srand((int)time(NULL));
	std::rand();
	switch (std::rand() % 3 + 1)
	{
	case 1:
		std::cout << "------A was generated------" << std::endl;
		return new A();
		break;
	case 2:
		std::cout << "------B was generated------" << std::endl;
		return new B();
		break;
	case 3:
		std::cout << "------C was generated------" << std::endl;
		return new C();
	}
	std::cout << "Error" << std::endl;
	return NULL;
}

void	identify(Base *p)
{
	if (p == NULL)
	{
		std::cout << "NULL pointer" << std::endl;
		return ;
	}
	std::cout << "Identificated. The object is an instance of ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Base" << std::endl;
}
