#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>

enum	NumType
{
	errorType = -1,
	charType,
	intType,
	floatType,
	doubleType
};

class	Converter
{
	private:
		std::string	num;
		NumType		numType;
		bool		pseudoliteral;
		char		cNum;
		int			iNum;
		float		fNum;
		double		dNum;
	public:
		Converter(std::string num);
		~Converter(void);

		NumType	checkNumType(std::string str);
		NumType	isPseudoliteral(std::string str);
		void	castNum(void);
		void	printNum(void) const;
};

#endif