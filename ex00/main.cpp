/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:38:29 by javmarti          #+#    #+#             */
/*   Updated: 2023/11/29 14:13:53 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char* argv[])
{
	if (argc != 2)
		std::cout << "Éste programa necesita un único número como parámetro" << std::endl;
	else
	{
		try
		{
			ScalarConverter::convert(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		
	}
	return 0;
}
