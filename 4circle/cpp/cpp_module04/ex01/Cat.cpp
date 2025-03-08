#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat& other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = NULL;
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assigment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

void    Cat::makeSound() const
{
    std::cout << "Meow~ Meow~" << std::endl;
}

Brain* Cat::getBrain() const
{
    return (this->brain);
}