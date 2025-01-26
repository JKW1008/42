#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook
{
private:
	int		CurIdx;
	Contact	Contacts[8];
public:
	PhoneBook();
	~PhoneBook();

	void	Add();
	void	Search();
};

#endif