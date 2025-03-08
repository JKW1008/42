#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default FragTrap")
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "Default FragTrap created"  << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "Name FragTrap " << name << " created"  << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "Copy FragTrap " << other.getName() << " created"  << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap " << other.getName() << " assigned from another FragTrap" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << getName() << " is destroyed" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (getEnergyPoints() > 0 && getHitPoints() > 0)
	{
		std::cout << "FragTrap " << getName() << " aggressively attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else
	{
		std::cout << "FragTrap " << getName() << " has no energy or hit points left to attack!" << std::endl;
	}
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->getName() << " requests a positive high five!" << std::endl;
}