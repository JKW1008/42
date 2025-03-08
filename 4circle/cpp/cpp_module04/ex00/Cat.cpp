#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
}

Cat::Cat(const Cat& other)
{
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Cat::~Cat()
{
}

void    Cat::makeSound() const
{
    std::cout << "Meow~ Meow~" << std::endl;
}