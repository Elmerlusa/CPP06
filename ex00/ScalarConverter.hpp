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
		
		typedef struct	sCastedNums
		{
			char	cNum;
			int		iNum;
			float	fNum;
			double	dNum;
			double	aux;
		}	tCastedNums;

		static bool	isValidNum(const std::string& str);
		static int	identifyPseudoliteral(const std::string& str);
		static int	identifyStrType(const std::string& str);
		
		static bool	isChar(const std::string& str);

		static void	castNum(const std::string& str, tCastedNums& castedNums, const int& type);
		static void	printNum(const std::string& str, const tCastedNums& castedNums);
		
		static std::string	getCharText(const tCastedNums& castedNums);

		virtual void	makeClassStatic(void) const = 0;
	public:
		static void	convert(const std::string& str);
};

#endif
