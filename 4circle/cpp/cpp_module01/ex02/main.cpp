#include <iostream>
// #include <string>

int main()
{
	std::string stackStr = "HI THIS IS BRAIN";
	std::string *stringPTR = &stackStr;
	std::string &stringREF = stackStr;

	std::cout << "Address : " << &stackStr << std::endl;
	std::cout << "stringPTR : " << stringPTR << std::endl;
	std::cout << "&stringREF : " << &stringREF << std::endl;

	std::cout << "Value : " << stackStr << std::endl;
	std::cout << "*stringPTR : " << *stringPTR << std::endl;
	std::cout << "stringREF : " << stringREF << std::endl;

	return (0);
}