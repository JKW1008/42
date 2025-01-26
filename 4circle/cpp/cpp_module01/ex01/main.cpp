#include "Zombie.hpp"

int	main()
{
	int	n = 10;
	Zombie	*hordes = zombieHorde(n, "not human");

	if (!hordes)
	{
		std::cout << "Failed" << std::endl;
		return (1);
	}
	for (int i = 0; i < n; i++)
	{
		hordes[i].announce();
	}
	delete[] hordes;
	return (0);
}