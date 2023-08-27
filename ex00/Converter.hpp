/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:38:27 by javmarti          #+#    #+#             */
/*   Updated: 2023/08/27 14:37:55 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <limits>

class	Converter
{
	private:
		std::string	num;
		char		cNum;
		int			iNum;
		float		fNum;
		double		dNum;
	public:
		Converter(std::string num);
		~Converter(void);

		bool	isPseudoliteral(std::string str) const;
		bool	isValidNum(std::string str) const;

		void	castNum(void);

		void		printNum(void) const;
		std::string	getCharText(void) const;
};

#endif