/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:38:27 by javmarti          #+#    #+#             */
/*   Updated: 2023/11/28 21:21:01 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <limits>
# include <cerrno>

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3
# define NOTYPE 4

class	ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& converter);
		~ScalarConverter(void);

		ScalarConverter&	operator=(const ScalarConverter& converter);

		static bool	isValidNum(const std::string& str);
		static int	identifyPseudoliteral(const std::string& str);
		static int	identifyStrType(const std::string& str);
		
		static bool	isChar(const std::string& str);

		static void	castAndPrintNum(const std::string& str, const int& type);
		static void	castAndPrintChar(const std::string& str);
		static void	castAndPrintInt(const std::string& str);
		static void	castAndPrintFloat(const std::string& str);
		static void	castAndPrintDouble(const std::string& str);

		virtual void	makeClassStatic(void) const = 0;
	public:
		static void	convert(const std::string& str);
};

#endif
