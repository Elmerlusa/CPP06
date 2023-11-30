/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:38:11 by javmarti          #+#    #+#             */
/*   Updated: 2023/11/30 15:38:17 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void);
void	identify(Base *p);
void	identify(Base& p);

int	main(void)
{
	Base*	x = generate();
	
	if (x != NULL)
	{
		identify(x);
		identify(*x);
		delete x;
	}
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
		case 2:
			std::cout << "------B was generated------" << std::endl;
			return new B();
		case 3:
			std::cout << "------C was generated------" << std::endl;
			return new C();
	}
	std::cout << "Error" << std::endl;
	return NULL;
}

void	identify(Base *p)
{
	std::cout << "Identificated. The pointer is an instance of ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Base" << std::endl;
}

void	identify(Base& p)
{
	Base	aux;
	
	std::cout << "Identificated. The reference is an instance of ";
	try
	{
		aux = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			aux = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				aux = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "Base" << std::endl;
			}
		}
	}
	(void) aux;
}
