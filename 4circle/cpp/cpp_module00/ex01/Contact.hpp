#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact
{
private:
	std::string	FirstName;
	std::string	LastName;
	std::string Nickname;
	std::string PhoneNumber;
	std::string DarkestSecret;
	int			Idx;
public:
	Contact();
	~Contact();

	const	std::string&	GetFirstName() const;
	const	std::string&	GetLastName() const;
	const	std::string&	GetNickname() const;
	const	std::string&	GetPhoneNumber() const;
	const	std::string&	GetDarkestSecret() const;
	int						GetIdx();

	void	SetFirstName(std::string input);
	void	SetLastName(std::string input);
	void	SetNickname(std::string input);
	void	SetPhoneNumber(std::string input);
	void	SetDarkestSecret(std::string input);
	void	SetIdx(int idx);
};

#endif