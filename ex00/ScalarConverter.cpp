/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:39:51 by javmarti          #+#    #+#             */
/*   Updated: 2023/11/28 21:27:19 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& converter)
{
	(void) converter;
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& converter)
{
	(void) converter;
	return *this;
}

int	ScalarConverter::identifyPseudoliteral(const std::string& str)
{
	const std::string	pseudoliterals[] = {"-inf", "+inf", "inf", "nan", ""};
	
	for (int i = 0; pseudoliterals[i].empty() == false; i++)
	{
		if (str == pseudoliterals[i])
			return DOUBLE;
		if (str == (pseudoliterals[i] + "f"))
			return FLOAT;
	}
	return NOTYPE;
}

bool	ScalarConverter::isValidNum(const std::string& str)
{
	std::string::const_iterator	it = str.begin();
	bool						decimal = false;

	if (str.empty())
		return false;
	if ((str.length() == 1 && std::isprint(*it) && std::isdigit(*it) == false) || ScalarConverter::identifyPseudoliteral(str) != NOTYPE)
		return true;
	if (it != str.end() && (*it == '-' || *it == '+'))
		it++;
	if (it == str.end() || std::isdigit(*it) == false)
		return false;
	while (it != str.end() && (std::isdigit(*it) || *it == '.'))
	{
		if (*it == '.')
		{
			if (decimal == true || (it + 1 == str.end() || std::isdigit(*(it + 1)) == false))
				return false;
			decimal = true;
		}
		it++;
	}
	return it == str.end() || (it != str.end() && decimal == true && *it == 'f' && it + 1 == str.end());
}

int	ScalarConverter::identifyStrType(const std::string& str)
{
	const int	pseudoliteralType = ScalarConverter::identifyPseudoliteral(str);
	
	if (ScalarConverter::isValidNum(str) == false)
		return NOTYPE;
	if (pseudoliteralType != NOTYPE)
		return pseudoliteralType;
	if (ScalarConverter::isChar(str))
		return CHAR;
	if (str.find('.') == std::string::npos)
		return INT;
	if (str[str.length() - 1] == 'f')
		return FLOAT;
	return DOUBLE;
}

bool	ScalarConverter::isChar(const std::string& str)
{
	return str.length() == 1 && std::isprint(str[0]) && std::isdigit(str[0]) == false;
}

void	ScalarConverter::castNum(const std::string& str, tCastedNums& castedNums, const int& type)
{
	castedNums.aux = castedNums.dNum = strtod(str.c_str(), NULL);
	if (type == CHAR)
	{
		castedNums.cNum = str[0];
		castedNums.iNum = static_cast<int>(castedNums.cNum);
		castedNums.fNum = static_cast<float>(castedNums.cNum);
		castedNums.dNum = static_cast<double>(castedNums.cNum);
	}
	else if (type == INT)
	{
		castedNums.iNum = atoi(str.c_str());
		castedNums.cNum = static_cast<char>(castedNums.iNum);
		castedNums.fNum = static_cast<float>(castedNums.iNum);
		castedNums.dNum = static_cast<double>(castedNums.iNum);
	}
	else if (type == FLOAT)
	{
		castedNums.fNum = strtof(str.c_str(), NULL);
		if (errno == ERANGE)
		{
			std::cout << "ERROR" << std::endl;
			if (str[0] == '-')
				castedNums.fNum = -std::numeric_limits<float>::infinity();
			else
				castedNums.fNum = std::numeric_limits<float>::infinity();
		}
		castedNums.cNum = static_cast<char>(castedNums.fNum);
		castedNums.iNum = static_cast<int>(castedNums.fNum);
		castedNums.dNum = static_cast<double>(castedNums.fNum);
	}
	else
	{
		castedNums.dNum = strtod(str.c_str(), NULL);
		if (errno == ERANGE)
		{
			std::cout << "ERROR" << std::endl;
			if (str[0] == '-')
				castedNums.dNum = -std::numeric_limits<double>::infinity();
			else
				castedNums.dNum = std::numeric_limits<double>::infinity();
		}
		castedNums.cNum = static_cast<char>(castedNums.dNum);
		castedNums.iNum = static_cast<int>(castedNums.dNum);
		castedNums.fNum = static_cast<float>(castedNums.dNum);
	}
}

void	ScalarConverter::printNum(const std::string& str, const tCastedNums& castedNums)
{
	std::cout << "char: " << ScalarConverter::getCharText(castedNums) << "\nint: ";
	if (castedNums.aux < -std::numeric_limits<int>::max() - 1
		|| std::numeric_limits<int>::max() < castedNums.aux || ScalarConverter::identifyPseudoliteral(str) != NOTYPE)
		std::cout << "impossible";
	else
		std::cout << castedNums.iNum;
	std::cout << "\nfloat: " << std::fixed << std::setprecision(1);
	if (castedNums.aux < -std::numeric_limits<float>::max() - 1
		|| std::numeric_limits<float>::max() < castedNums.aux)
		std::cout << castedNums.aux > 0 ? std::numeric_limits<float>::infinity() : -std::numeric_limits<float>::infinity();
	else
		std::cout << castedNums.fNum;
	std::cout << "f\ndouble: " << castedNums.dNum << std::endl;
}

std::string	ScalarConverter::getCharText(const tCastedNums& castedNums)
{
	std::string	charText(1, castedNums.cNum);

	if (castedNums.iNum < -std::numeric_limits<char>::max() - 1 || std::numeric_limits<char>::max() < castedNums.iNum)
		charText = "impossible";
	else if (std::isprint(castedNums.cNum) == false)
		charText = "Non displayable";
	return charText;
}

void	ScalarConverter::convert(const std::string& str)
{
	const int	type = ScalarConverter::identifyStrType(str);
	
	if (type == NOTYPE)
		std::cout << "El parámetro no es un número válido" << std::endl;
	else
	{
		tCastedNums	castedNums;
		
		castNum(str, castedNums, type);
		printNum(str, castedNums);
	}
}
