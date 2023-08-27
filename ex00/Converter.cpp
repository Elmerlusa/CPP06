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

Converter::Converter(std::string num)
{
	if (this->isValidNum(num) == false)
		throw std::invalid_argument("El parámetro no es un número válido");
	this->num = num;
	this->castNum();
	if (num[num.size() - 1] == 'f' && this->isPseudoliteral(num) == false
		&& (this->dNum < -std::numeric_limits<float>::max() - 1
		|| std::numeric_limits<float>::max() < this->dNum))
		throw std::invalid_argument("El parámetro es imposible de representar como float");
	if (num.rfind('.', std::string::npos) == std::string::npos && this->isPseudoliteral(num) == false
		&& (this->dNum < -std::numeric_limits<int>::max() - 1 || std::numeric_limits<int>::max() < this->dNum))
		throw std::invalid_argument("El parámetro es imposible de representar como int");
	this->printNum();
}

Converter::~Converter(void) {}

bool	Converter::isPseudoliteral(std::string str) const
{
	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("inff") == 0 || str.compare("nanf") == 0)
		return true;
	if (str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("inf") == 0 || str.compare("nan") == 0)
		return true;
	return false;
}

bool	Converter::isValidNum(std::string str) const
{
	std::string::const_iterator	it = str.begin();
	bool						decimal = false;

	if (str.empty())
		return false;
	if (str.length() == 1 && std::isprint(*it) && std::isdigit(*it) == false)
		return true;
	if (this->isPseudoliteral(str))
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
	if (this->num.length() == 1 && std::isprint(this->num[0]) 
		&& std::isdigit(this->num[0]) == false)
	{
		this->cNum = this->num[0];
		this->iNum = static_cast<int>(this->cNum);
		this->fNum = static_cast<float>(this->cNum);
		this->dNum = static_cast<double>(this->cNum);
	}
	else
	{
		this->dNum = strtod(this->num.c_str(), NULL);
		this->cNum = static_cast<char>(this->dNum);
		this->iNum = static_cast<int>(this->dNum);
		this->fNum = static_cast<float>(this->dNum);	
	}
}

void	Converter::printNum(void) const
{
	std::cout << "char: " << this->getCharText() << "\nint: ";
	if (this->dNum < -std::numeric_limits<int>::max() - 1
		|| std::numeric_limits<int>::max() < this->dNum || this->isPseudoliteral(this->num))
		std::cout << "impossible";
	else
		std::cout << this->iNum;
	std::cout << "\nfloat: " << std::fixed << std::setprecision(1);
	if (this->isPseudoliteral(this->num) == false && (this->dNum < -std::numeric_limits<float>::max() - 1
		|| std::numeric_limits<float>::max() < this->dNum))
		std::cout << "impossible";
	else
		std::cout << this->fNum << "f";
	std::cout << "\ndouble: " << this->dNum << std::endl;
}

std::string	Converter::getCharText(void) const
{
	std::string	charText(1, this->cNum);

	if (this->iNum < -std::numeric_limits<char>::max() - 1
		|| std::numeric_limits<char>::max() < this->iNum)
		charText = "impossible";
	else if (std::isprint(this->cNum) == false)
		charText = "Non displayable";
	return charText;
}
