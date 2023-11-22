/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:38:26 by javmarti          #+#    #+#             */
/*   Updated: 2023/08/27 15:27:53 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(void): _num("0"), _cNum('0'), _iNum(0), _fNum(0), _dNum(0)
{
}

Converter::Converter(const Converter& converter):
	_num(converter.getNum()), _cNum(converter.getCNum()), _iNum(converter.getINum()), _fNum(converter.getFNum()), _dNum(converter.getDNum())
{
}

Converter::Converter(const std::string& num): _num(num)
{
	if (this->isValidNum(num) == false)
		throw std::invalid_argument("El parámetro no es un número válido");
	this->castNum();
	if (this->isPseudoliteral(num) == false)
	{
		if (num[num.size() - 1] == 'f' && (this->_dNum < -std::numeric_limits<float>::max() - 1 || std::numeric_limits<float>::max() < this->_dNum))
			throw std::invalid_argument("El parámetro es imposible de representar como float");
		if (num.rfind('.', std::string::npos) == std::string::npos && (this->_dNum < -std::numeric_limits<int>::max() - 1 || std::numeric_limits<int>::max() < this->_dNum))
			throw std::invalid_argument("El parámetro es imposible de representar como int");
	}
	this->printNum();
}

Converter::~Converter(void)
{
}

const std::string&	Converter::getNum(void) const
{
	return this->_num;
}
const char&			Converter::getCNum(void) const
{
	return this->_cNum;
}
const int&			Converter::getINum(void) const
{
	return this->_iNum;
}
const float&		Converter::getFNum(void) const
{
	return this->_fNum;
}
const double&		Converter::getDNum(void) const
{
	return this->_dNum;
}

bool	Converter::isPseudoliteral(const std::string& str) const
{
	return (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("inff") == 0 || str.compare("nanf") == 0)
		|| (str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("inf") == 0 || str.compare("nan") == 0);
}

bool	Converter::isValidNum(const std::string& str) const
{
	std::string::const_iterator	it = str.begin();
	bool						decimal = false;

	if (str.empty())
		return false;
	if ((str.length() == 1 && std::isprint(*it) && std::isdigit(*it) == false) || this->isPseudoliteral(str))
		return true;
	if (it != str.end() && (*it == '-' || *it == '+'))
		it++;
	while (it != str.end() && (std::isdigit(*it) || *it == '.'))
	{
		if (*it == '.' && decimal == true)
			return false;
		else if (*it == '.' && (it + 1 == str.end() || std::isdigit(*(it + 1)) == false))
			return false;
		else if (*it == '.')
			decimal = true;
		it++;
	}
	if (it != str.end() && *it == 'f' && it + 1 == str.end())
		return true;
	return it == str.end();
}

void	Converter::castNum(void)
{
	if (this->_num.length() == 1 && std::isprint(this->_num[0]) && std::isdigit(this->_num[0]) == false)
	{
		this->_cNum = this->_num[0];
		this->_iNum = static_cast<int>(this->_cNum);
		this->_fNum = static_cast<float>(this->_cNum);
		this->_dNum = static_cast<double>(this->_cNum);
	}
	else
	{
		this->_dNum = strtod(this->_num.c_str(), NULL);
		this->_cNum = static_cast<char>(this->_dNum);
		this->_iNum = static_cast<int>(this->_dNum);
		this->_fNum = static_cast<float>(this->_dNum);	
	}
}

void	Converter::printNum(void) const
{
	std::cout << "char: " << this->getCharText() << "\nint: ";
	if (this->_dNum < -std::numeric_limits<int>::max() - 1
		|| std::numeric_limits<int>::max() < this->_dNum || this->isPseudoliteral(this->_num))
		std::cout << "impossible";
	else
		std::cout << this->_iNum;
	std::cout << "\nfloat: " << std::fixed << std::setprecision(1);
	if (this->isPseudoliteral(this->_num) == false && (this->_dNum < -std::numeric_limits<float>::max() - 1
		|| std::numeric_limits<float>::max() < this->_dNum))
		std::cout << "impossible";
	else
		std::cout << this->_fNum << "f";
	std::cout << "\ndouble: " << this->_dNum << std::endl;
}

std::string	Converter::getCharText(void) const
{
	std::string	charText(1, this->_cNum);
	bool		decimal = static_cast<float>(this->_iNum) != this->_fNum;

	if (decimal || this->_iNum < -std::numeric_limits<char>::max() - 1 || std::numeric_limits<char>::max() < this->_iNum)
		charText = "impossible";
	else if (std::isprint(this->_cNum) == false)
		charText = "Non displayable";
	return charText;
}

Converter&	Converter::operator=(const Converter& converter)
{
	if (this != &converter)
	{
		this->_num = converter.getNum();
		this->_cNum = converter.getCNum();
		this->_iNum = converter.getINum();
		this->_fNum = converter.getFNum();
		this->_dNum = converter.getDNum();
	}
	return *this;
}
