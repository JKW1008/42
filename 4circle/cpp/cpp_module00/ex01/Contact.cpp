#include "Contact.hpp"

Contact::Contact()
{
};

Contact::~Contact()
{
};

const std::string&	Contact::GetFirstName() const
{
	return (FirstName);
}

const std::string&	Contact::GetLastName() const
{
	return (LastName);
}

const std::string&	Contact::GetNickname() const
{
	return (Nickname);
}

const std::string&	Contact::GetPhoneNumber() const
{
	return (PhoneNumber);
}

const std::string&	Contact::GetDarkestSecret() const
{
	return (DarkestSecret);
}

int	Contact::GetIdx()
{
	return (Idx);
}

void	Contact::SetFirstName(std::string input)
{
	FirstName = input;
}

void	Contact::SetLastName(std::string input)
{
	LastName = input;
}

void	Contact::SetNickname(std::string input)
{
	Nickname = input;
}

void	Contact::SetPhoneNumber(std::string input)
{
	PhoneNumber = input;
}

void	Contact::SetDarkestSecret(std::string input)
{
	DarkestSecret = input;
}

void	Contact::SetIdx(int index)
{
	Idx = index;
}