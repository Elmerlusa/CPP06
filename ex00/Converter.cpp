/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:38:26 by javmarti          #+#    #+#             */
/*   Updated: 2023/08/25 13:38:27 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(std::string num)
{
	if (this->isValidNum(num) == false)
		throw std::invalid_argument("El parámetro no es un número válido");
	this->num = num;
	this->numType = this->identifyNumType();
}

Converter::~Converter(void) {}

bool	Converter::isPseudoliteral(std::string str)
{
	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("inff") == 0 || str.compare("nanf") == 0)
		return true;
	if (str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("inf") == 0 || str.compare("nan") == 0)
		return true;
	return false;
}

bool	Converter::isValidNum(std::string str)
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

NumType	Converter::identifyNumType(void)
{
	std::string::const_iterator	it = num.begin();
	NumType						pseudoliteralType = this->identifyPseudoliteral();
	bool						decimal = num.rfind('.', std::string::npos) != std::string::npos;
	size_t						len = this->num.length();
	double						dNum;
	
	if (pseudoliteralType != errorType)
		return pseudoliteralType;
	if (len == 1 && std::isprint(*it) && std::isdigit(*it) == false)
		return charType;
	{
		std::string					auxNum;

		auxNum = this->num[len - 1] == 'f' ? this->num.substr(0, len - 1) : this->num;
		dNum = strtod(auxNum.c_str(), NULL);
	}	
	if (this->num[len - 1] == 'f')
	{
		if (dNum < -std::numeric_limits<float>::max() || std::numeric_limits<float>::max() < dNum)
			throw std::runtime_error("El número está fuera de los límites del float y por tanto es erróneo");
		return floatType;
	}
	if (decimal == false && (dNum < -std::numeric_limits<int>::max() - 1 || std::numeric_limits<int>::max() < dNum))
		return doubleType;
	else
		return intType;
}

NumType	Converter::identifyPseudoliteral(void)
{
	this->pseudoliteral = true;
	if (this->num.compare("-inff") == 0 || this->num.compare("+inff") == 0 || this->num.compare("inff") == 0 || this->num.compare("nanf") == 0)
		return floatType;
	if (this->num.compare("-inf") == 0 || this->num.compare("+inf") == 0 || this->num.compare("inf") == 0 || this->num.compare("nan") == 0)
		return doubleType;
	this->pseudoliteral = false;
	return errorType;
}

void	Converter::castNum(void)
{
	switch (this->numType)
	{
		case errorType:
			break ;
		case charType:
			this->cNum = this->num[0];
			this->iNum = static_cast<int>(this->cNum);
			this->fNum = static_cast<float>(this->cNum);
			this->dNum = static_cast<double>(this->cNum);
			break ;
		case intType:
			this->iNum = atoi(this->num.c_str());
			this->cNum = static_cast<char>(this->iNum);
			this->fNum = static_cast<float>(this->iNum);
			this->dNum = static_cast<double>(this->iNum);
			break ;
		case floatType:
			this->fNum = atof(this->num.c_str());
			this->cNum = static_cast<char>(this->fNum);
			this->iNum = static_cast<int>(this->fNum);
			this->dNum = static_cast<double>(this->fNum);
			break ;
		case doubleType:
			this->dNum = strtod(this->num.c_str(), NULL);
			this->cNum = static_cast<char>(this->dNum);
			this->iNum = static_cast<int>(this->dNum);
			this->fNum = static_cast<float>(this->dNum);
			break ;
	}
}

void	Converter::printNum(void) const
{
	std::cout << "char: " << this->getCharText() << "\nint: ";
	if (this->dNum > std::numeric_limits<int>::max())
		std::cout << this->dNum << "DOUBLE > INT_MAX" << std::endl;
	if (this->dNum < -std::numeric_limits<int>::max() - 1)
		std::cout << this->dNum << "DOUBLE < INT_MIN" << std::endl;
	if (this->pseudoliteral || this->dNum < -std::numeric_limits<int>::max() - 1 || std::numeric_limits<int>::max() < this->dNum)
		std::cout << "impossible";
	else
		std::cout << this->iNum;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "\nfloat: " << this->fNum << "f\n"
			<< "double: " << this->dNum << std::endl;
}

std::string	Converter::getCharText(void) const
{
	std::string	charText(1, this->cNum);

	if (this->iNum < 0 || 127 < this->iNum || this->pseudoliteral)
		charText = "impossible";
	else if (std::isprint(this->cNum) == false)
		charText = "Non displayable";
	return charText;
}