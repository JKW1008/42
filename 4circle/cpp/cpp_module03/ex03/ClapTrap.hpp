#ifndef	CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();

		ClapTrap 		&operator=(const ClapTrap &other);

		void			attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		std::string		getName() const;
		unsigned int	getHitPoints() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;

		void			setName(const std::string &newName);
		void			setHitPoints(unsigned int newHitPoints);
		void			setEnergyPoints(unsigned int newEnergyPoints);
		void			setAttackDamage(unsigned int newAttackDamage);
};

#endif