#include "AAnimal.hpp"


AAnimal::AAnimal() : type("AAnimal")
{
}

AAnimal::AAnimal(const AAnimal& other)
{
    *this = other;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

AAnimal::~AAnimal()
{
}
