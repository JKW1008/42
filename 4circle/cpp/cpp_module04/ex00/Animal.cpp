#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
}

Animal::Animal(const Animal& other)
{
    *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Animal::~Animal()
{
}

std::string	Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
    std::cout << "Animal makes a generic sound!" << std::endl;
}