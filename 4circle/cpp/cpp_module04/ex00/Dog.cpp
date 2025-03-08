#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Dog::~Dog()
{
}

void    Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}