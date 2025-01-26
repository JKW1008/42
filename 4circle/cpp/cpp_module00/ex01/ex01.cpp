#include "ex01.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	input;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT) : ";
		std::getline(std::cin, input);
		if (HandleEOF() || input == "EXIT")
			break ;
		else if (input == "ADD")
			phonebook.Add();
		else if (input == "SEARCH")
			phonebook.Search();
		else
			std::cout << "Enter wrong command" << std::endl;
	}
	return (0);
}