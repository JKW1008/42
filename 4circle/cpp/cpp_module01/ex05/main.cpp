#include "Harl.hpp"
#include <iostream>

int	main(void)
{
	Harl	harl;

	std::cout << "Testing Harl's complaint level : \n" << std::endl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	std::cout << "Testing invalid level : \n" << std::endl;
	harl.complain("INVALID");

	return (0);
}