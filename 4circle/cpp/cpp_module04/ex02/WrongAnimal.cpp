#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") 
{
	std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
	std::cout << "Copy WrongAnimal constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Copy WrongAnimal  operator called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal desturctor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes a generic sound!" << std::endl;
}