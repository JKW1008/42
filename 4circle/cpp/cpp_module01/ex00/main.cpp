#include "Zombie.hpp"

int main()
{
	Zombie *heap_zombie = newZombie("Cardi B");
	Zombie	stack("stack");
	heap_zombie->announce();
	stack.announce();
	delete heap_zombie;
	return (0);
}