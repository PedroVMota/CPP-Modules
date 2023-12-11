#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie *Chump = new Zombie(name);
	Chump->announce();
	delete Chump;
}