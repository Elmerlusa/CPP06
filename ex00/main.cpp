/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:38:29 by javmarti          #+#    #+#             */
/*   Updated: 2023/08/27 14:36:40 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

void	convertString(std::string str);

int	main(int argc, char* argv[])
{
	if (argc != 2)
		std::cout << "Éste programa necesita un único número como parámetro" << std::endl;
	else
		convertString(argv[1]);
	return 0;
}

void	convertString(const std::string str)
{
	try
	{
		Converter	c(str);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}