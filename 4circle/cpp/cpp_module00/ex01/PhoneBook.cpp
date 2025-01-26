#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include "ex01.hpp"

PhoneBook::PhoneBook()
{
	CurIdx = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::Add()
{
	Contact		info;
	std::string	input;

	info.SetIdx(CurIdx % 8);

	std::cout << "Insert your first name : ";
	std::getline(std::cin, input);
	if (HandleEOF() == 1)
		return ;
	info.SetFirstName(input);

	std::cout << "Insert your last name : ";
	std::getline(std::cin, input);
	if (HandleEOF() == 1)
		return ;
	info.SetLastName(input);

	std::cout << "Insert your nickname : ";
	std::getline(std::cin, input);
	if (HandleEOF() == 1)
		return ;
	info.SetNickname(input);

	std::cout << "Insert your phonenumber : ";
	input = InsertPhonenumber();
	if (input.empty())
		return ;
	info.SetPhoneNumber(input);

	std::cout << "Insert your darkest secret : ";
	std::getline(std::cin, input);
	if (HandleEOF() == 1)
		return ;
	info.SetDarkestSecret(input);

	Contacts[CurIdx % 8] = info;
	CurIdx++;
}

void	PhoneBook::Search()
{
	std::string	input;
	int			idx;

	PrintHeader();

	for (int i = 0; i < 8; i++)
	{
		if (i < CurIdx)
		{
			std::cout << std::setw(10) << i << "|"
					<< std::setw(10) << (Contacts[i].GetFirstName().length() > 10 ?
					Contacts[i].GetFirstName().substr(0, 9) + "." :
					Contacts[i].GetFirstName()) << "|"
					<< std::setw(10) << (Contacts[i].GetLastName().length() > 10 ?
					Contacts[i].GetLastName().substr(0, 9) + "." :
					Contacts[i].GetLastName()) << "|"
					<< std::setw(10) << (Contacts[i].GetNickname().length() > 10 ?
					Contacts[i].GetNickname().substr(0, 9) + "." :
					Contacts[i].GetNickname()) << std::endl;
		}
	}

	std::cout << "Enter index to view details (0 ~ 7) : ";
	std::getline(std::cin, input);
	if (HandleEOF() == 1)
		return ;

	if (input.length() != 1 || !isdigit(input[0]))
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	idx = input[0] - '0';
	if (idx >= CurIdx || idx > 7)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	std::cout << "First Name : " << Contacts[idx].GetFirstName() << std::endl;
	std::cout << "Last Name : " << Contacts[idx].GetLastName() << std::endl;
	std::cout << "Nickname : " << Contacts[idx].GetNickname() << std::endl;
	std::cout << "Phone Number : " << Contacts[idx].GetPhoneNumber() << std::endl;
	std::cout << "Dakest Secret : " << Contacts[idx].GetDarkestSecret() << std::endl;
	
	PrintFooter();
}