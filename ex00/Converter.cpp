#include "Converter.hpp"

Converter::Converter(std::string num)
{
	this->numType = this->checkNumType(num);

	if (this->numType == errorType)
		throw std::invalid_argument("El parámetro no es un número válido");
	this->num = num;
}

Converter::~Converter(void) {}

NumType	Converter::checkNumType(std::string str)
{
	std::string::const_iterator	it = str.begin();
	NumType						pseudoliteral = this->isPseudoliteral(str);
	bool						decimal = false;

	if (str.empty())
		return errorType;
	if (pseudoliteral != errorType)
		return pseudoliteral;
	if (str.length() == 1 && std::isprint(*it) && std::isdigit(*it) == false)
		return charType;
	if (it != str.end() && (*it == '-' || *it == '+'))
		it++;
	while (it != str.end() && (std::isdigit(*it) || *it == '.'))
	{
		if (*it == '.' && decimal == true)
			return errorType;
		else if (*it == '.')
			decimal = true;
		it++;
	}
	if (it != str.end() && *it == 'f' && it + 1 == str.end() && decimal == true)
		return floatType;
	if (it != str.end())
		return errorType;
	return decimal ? doubleType : intType;
}

NumType	Converter::isPseudoliteral(std::string str)
{
	this->pseudoliteral = true;
	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("inff") == 0 || str.compare("nanf") == 0)
		return floatType;
	if (str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("inf") == 0 || str.compare("nan") == 0)
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
	bool		printDecimalPart = this->numType == charType || this->numType == intType || this->fNum == this->iNum;
	std::string	charText(1, this->cNum);

	if (this->iNum < 0 || 127 < this->iNum || this->pseudoliteral)
		charText = "impossible";
	else if (std::isprint(this->cNum) == false)
		charText = "Non displayable";
	std::cout << "char: " << charText << "\nint: ";
	if (this->pseudoliteral)
		std::cout << "impossible";
	else
		std::cout << this->iNum;
	std::cout << "\nfloat: " << this->fNum << (printDecimalPart ? ".0" : "") << "f\n"
			<< "double: " << this->dNum << (printDecimalPart ? ".0" : "") << std::endl;
}