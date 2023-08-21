#include "Converter.hpp"

void	convertString(std::string str);

int	main(int argc, char* argv[])
{
	if (argc != 2)
		std::cerr << "Éste programa necesita un único parámetro" << std::endl;
	else
		convertString(argv[1]);
	return 0;
}

void	convertString(std::string str)
{
	try
	{
		Converter	c(str);
		c.castNum();
		c.printNum();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}