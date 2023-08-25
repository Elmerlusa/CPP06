/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:37:47 by javmarti          #+#    #+#             */
/*   Updated: 2023/08/25 13:43:35 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

#include "Data.hpp"

uintptr_t	serialize(Data* ptr);
Data*	deserialize(uintptr_t raw);
void	printData(Data* d);

int	main(void)
{
	{
		uintptr_t	p;
		Data*		result;

		std::cout << "Serializing and deserializing NULL" << std::endl;
		p = serialize(NULL);
		result = deserialize(p);
		std::cout << "RESULT (uintptr_t = " << p << "): ";
		printData(result);
	}
	{
		Data*		d = new Data();
		uintptr_t	p;
		Data*		result;

		d->id = 99;
		d->name = "El Nano";
		d->age = 42;
		std::cout << "Serializing and deserializing ";
		printData(d);
		p = serialize(d);
		result = deserialize(p);
		std::cout << "RESULT (uintptr_t = " << p << "): ";
		printData(result);
		delete d;
	}
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
		std::cout << "Data(" << d->id << ", " << d->name << ", " << d->age << ")" << std::endl;
}
