#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Default ClapTrap created"  << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Name ClapTrap " << name << " created"  << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
	std::cout << "Copy ClapTrap " << other.name << " created"  << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap is destroyed" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
		std::cout << "ClapTrap " << this->name << " assigned from another FragTrap" << std::endl;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " has no hit points left and cannot act!" << std::endl;
		return ;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy points left and cannot attack!" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " 
				<< this->attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is already down and can't take more damage" << std::endl;
		return ;
	}
	if (amount >= this->hitPoints)
	{
		this->hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage and is knocked out!" << std::endl;
	}
	else
	{
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage! Remaining HP : " << this->hitPoints << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy points left and cannot repair..." << std::endl;
		return ;
	}
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is already destroyed and cannot be repaired..." << std::endl;
		return ;
	}
	this->energyPoints--;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " repairs itself for " << amount << " hit points! Remaining HP : " << this->hitPoints << std::endl;
}

std::string	ClapTrap::getName() const
{
	return (this->name);
}

unsigned int	ClapTrap::getHitPoints() const
{
	return (this->hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return (this->energyPoints);
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return (this->attackDamage);
}

void	ClapTrap::setName(const std::string &newName)
{
	this->name = newName;
}

void	ClapTrap::setHitPoints(unsigned int newHitPoints)
{
	this->hitPoints = newHitPoints;
}

void	ClapTrap::setEnergyPoints(unsigned int newEnergyPoints)
{
	this->energyPoints = newEnergyPoints;
}

void	ClapTrap::setAttackDamage(unsigned int newAttackDamage)
{
	this->attackDamage = newAttackDamage;
}