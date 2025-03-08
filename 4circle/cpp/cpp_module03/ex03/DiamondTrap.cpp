#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap()
{
	this->name = "Default";
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	FragTrap::setAttackDamage(30);
	this->setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "Default DiamondTrap created" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	FragTrap::setAttackDamage(30);
	this->setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "Name DiamondTrap " << name << " created"  << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	this->name = other.name;
	std::cout << "Copy DiamondTrap " << this->name << " created"  << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->name = other.name;
	}
	std::cout << "DiamondTrap " << this->name << " assigned from another FragTrap" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name << " is destroyed" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I'm DiamondTrap " << this->name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}