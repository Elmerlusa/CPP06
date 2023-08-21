#include "Converter.hpp"

Converter::Converter(std::string num)
{
	if (this->isValidNum(num) == false)
		throw std::invalid_argument("El parámetro no es un número válido");
	this->num = num;
}

Converter::~Converter(void) {}

bool	Converter::isValidNum(std::string str) const
{
	std::string::const_iterator	it = str.begin();

	if (it != str.end() && (*it == '-' || *it == '+'))
		it++;
	while (it != str.end() && std::isdigit(*it))
		it++;
	return str.empty() == false && it == str.end();
}

void	Converter::castNum(void)
{
	std::istringstream(this->num) >> this->cNum;
	std::istringstream(this->num) >> this->iNum;
	std::istringstream(this->num) >> this->fNum;
	std::istringstream(this->num) >> this->dNum;
}

void	Converter::printNum(void) const
{
	std::cout << "char: " << this->cNum << "\n"
			<< "int: " << this->iNum << "\n"
			<< "float: " << this->fNum << "f\n"
			<< "double: " << this->dNum << std::endl;
}