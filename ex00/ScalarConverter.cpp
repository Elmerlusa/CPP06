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

void	ScalarConverter::castAndPrintNum(const std::string& str, const int& type)
{
	switch (type)
	{
		case CHAR:
			ScalarConverter::castAndPrintChar(str);
			break;
		case INT:
			ScalarConverter::castAndPrintInt(str);
			break;
		case FLOAT:
			ScalarConverter::castAndPrintFloat(str);
			break;
		case DOUBLE:
			ScalarConverter::castAndPrintDouble(str);
			break;
		default:
			throw std::runtime_error("Error");
	}
}

void	ScalarConverter::castAndPrintChar(const std::string& str)
{
	std::cout << "char: " << str[0] << "\n"
		<< "int: " << static_cast<int>(str[0]) << "\n"
		<< std::fixed << std::setprecision(1)
		<< "float: " << static_cast<float>(str[0]) << "f\n"
		<< "double: " << static_cast<double>(str[0]) << std::endl;
}

void	ScalarConverter::castAndPrintInt(const std::string& str)
{
	const double	aux = strtod(str.c_str(), NULL);

	if (errno == ERANGE || (aux < static_cast<double>(-std::numeric_limits<int>::max() - 1)
		|| static_cast<double>(std::numeric_limits<int>::max()) < aux))
	{
		std::cout << "char: conversion does not make sense: int overflow\n"
			<< "int: impossible\n"
			<< "float: conversion does not make sense: int overflow\n"
			<< "double: conversion does not make sense: int overflow" << std::endl;
	}
	else
	{
		const int		iNum = atoi(str.c_str());

		if (iNum < static_cast<int>(-std::numeric_limits<char>::max() - 1)
			|| static_cast<int>(std::numeric_limits<char>::max()) < iNum)
			std::cout << "char: impossible\n";
		else if (std::isprint(iNum) == false)
			std::cout << "char: non displayable\n";
		else
			std::cout << "char: " << static_cast<char>(iNum) << "\n";
		std::cout << "int: " << iNum << "\n"
			<< std::fixed << std::setprecision(1)
			<< "float: " << static_cast<float>(iNum) << "f\n"
			<< "double: " << static_cast<double>(iNum) << std::endl;
	}
}

void	ScalarConverter::castAndPrintFloat(const std::string& str)
{
	float	fNum = strtof(str.c_str(), NULL);

	if (errno == ERANGE || str == "nanf")
	{
		if (errno == ERANGE)
			fNum = str[0] == '-' ? strtof("-inff", NULL) : strtof("+inff", NULL);
		std::cout << "char: impossible\n"
			<< "int: impossible\n"
			<< "float: " << fNum << "f\n"
			<< "double: " << static_cast<double>(fNum) << std::endl;
	}
	else
	{
		if (fNum < static_cast<float>(-std::numeric_limits<char>::max() - 1)
			|| static_cast<float>(std::numeric_limits<char>::max()) < fNum)
			std::cout << "char: impossible\n";
		else if (std::isprint(static_cast<int>(fNum)) == false)
			std::cout << "char: non displayable\n";
		else
			std::cout << "char: " << static_cast<char>(fNum) << "\n";
		if (fNum < static_cast<float>(-std::numeric_limits<int>::max() - 1)
			|| static_cast<float>(std::numeric_limits<int>::max()) < fNum)
			std::cout << "int: impossible\n";
		else
			std::cout << "int: " << static_cast<int>(fNum) << "\n";
		std::cout << std::fixed << std::setprecision(1)
			<< "float: " << fNum << "f\n"
			<< "double: " << static_cast<double>(fNum) << std::endl;
	}
}

void	ScalarConverter::castAndPrintDouble(const std::string& str)
{
	double	dNum = strtod(str.c_str(), NULL);

	if (errno == ERANGE || str == "nan")
	{
		if (errno == ERANGE)
			dNum = str[0] == '-' ? strtof("-inf", NULL) : strtof("+inf", NULL);
		std::cout << "char: impossible\n"
			<< "int: impossible\n"
			<< "float: " << static_cast<float>(dNum) << "f\n"
			<< "double: " << dNum << std::endl;
	}
	else
	{
		if (dNum < static_cast<double>(-std::numeric_limits<char>::max() - 1)
			|| static_cast<double>(std::numeric_limits<char>::max()) < dNum)
			std::cout << "char: impossible\n";
		else if (std::isprint(static_cast<int>(dNum)) == false)
			std::cout << "char: non displayable\n";
		else
			std::cout << "char: " << static_cast<char>(dNum) << "\n";
		if (dNum < static_cast<double>(-std::numeric_limits<int>::max() - 1)
			|| static_cast<double>(std::numeric_limits<int>::max()) < dNum)
			std::cout << "int: impossible\n";
		else
			std::cout << "int: " << static_cast<int>(dNum) << "\n";
		std::cout << std::fixed << std::setprecision(1);
		if (dNum < static_cast<double>(-std::numeric_limits<float>::max() - 1)
			|| static_cast<double>(std::numeric_limits<float>::max()) < dNum)
		{
			if (str[0] == '-')
				std::cout << "float: -inff\n";
			else
				std::cout << "float: inff\n";
		}
		else
			std::cout << "float: " << static_cast<float>(dNum) << "\n";
		std::cout << "double: " << dNum << std::endl;
	}
}

void	ScalarConverter::convert(const std::string& str)
{
	const int	type = ScalarConverter::identifyStrType(str);
	
	if (type == NOTYPE)
		std::cout << "El parámetro no es un número válido" << std::endl;
	else
		castAndPrintNum(str, type);
}
