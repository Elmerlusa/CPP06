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
		std::string	_num;
		char		_cNum;
		int			_iNum;
		float		_fNum;
		double		_dNum;

		Converter(void);

		const std::string&	getNum(void) const;
		const char&			getCNum(void) const;
		const int&			getINum(void) const;
		const float&		getFNum(void) const;
		const double&		getDNum(void) const;

		bool	isPseudoliteral(const std::string& str) const;
		bool	isValidNum(const std::string& str) const;

		void	castNum(void);

		void		printNum(void) const;
		std::string	getCharText(void) const;
	public:
		Converter(const Converter& converter);
		Converter(const std::string& num);
		~Converter(void);

		Converter&	operator=(const Converter& converter);
};

#endif