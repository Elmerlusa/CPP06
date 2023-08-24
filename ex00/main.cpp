#include "Converter.hpp"

void	convertString(std::string str);

int	main(int argc, char* argv[])
{
	if (argc != 2)
		std::cout << "Éste programa necesita un único número como parámetro" << std::endl;
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
		std::cout << e.what() << std::endl;
	}
}