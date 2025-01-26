#include "ex01.hpp"
#include <iomanip>

int	HandleEOF()
{
	if (std::cin.eof())
	{
		std::cout << "Input End" << std::endl;
		std::cin.clear();
		std::cin.sync();
		return (1);
	}
	return (0);
}

int	CheckPhonenumber(std::string input)
{
	if (input.empty())
		return (0);
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '-')
			return (0);
	}
	return (1);
}

std::string	InsertPhonenumber()
{
	std::string	input;

	while (true)
	{
		std::getline(std::cin, input);
		if (HandleEOF() == 1)
			return (std::string());
		if (CheckPhonenumber(input) == 1)
			break ;
		std::cout << "Insert your phone number : ";
	}
	return (input);
}

void	PrintHeader()
{
	std::cout << std::endl;
	std::cout << std::right
			<< std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << std::endl;
}

void	PrintFooter()
{
	std::cout << std::endl;
}