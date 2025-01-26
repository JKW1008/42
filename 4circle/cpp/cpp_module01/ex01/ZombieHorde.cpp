#include "Zombie.hpp"
#include <sstream>
#include <limits>

Zombie	*zombieHorde(int n, std::string name)
{
	if (n <= 0 || n > std::numeric_limits<int>::max() / sizeof(Zombie))
		return (NULL);

	Zombie* horde = new Zombie[n];
	if (!horde)
		return (NULL);
	std::stringstream	ss;

	for (int i = 0; i < n; i++)
	{
		ss.str("");
		ss.clear();
		ss << name << "_" << i + 1;
		horde[i].setName(ss.str());
	}
	return (horde);
}
