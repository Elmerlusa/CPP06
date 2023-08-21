#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>

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

		bool	isValidNum(std::string str) const;
		void	castNum(void);
		void	printNum(void) const;
};

#endif