#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _count(0)
{
    for (int i = 0; i < 4; i++)
        _templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) : _count(0)
{
    for (int i = 0; i < 4; i++)
        _templates[i] = NULL;
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_templates[i])
                delete _templates[i];
            _templates[i] = NULL;
        }
        _count = other._count;
        for (int i = 0; i < 4; i++)
        {
            if (other._templates[i])
                _templates[i] = other._templates[i]->clone();
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_templates[i])
            delete _templates[i];
    }
}

void    MateriaSource::learnMateria(AMateria* m)
{
    if (_count < 4 && m)
    {
        _templates[_count] = m;
        _count++;
    }
}

AMateria*   MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_templates[i] && _templates[i]->getType() == type)
            return (_templates[i]->clone());
    }
    return (NULL);
}