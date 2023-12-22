#include "Zombie.hpp"
#include <limits>

int main()
{
	int numZombies = 10;
	std::string zombieName = "Execito de Portugal";

	Zombie *zombieArray = zombieHorde(numZombies, zombieName);

	// Call announce for each zombie
	for (int i = 0; i < numZombies; i++)
		zombieArray[i].announce();

	// Delete the array when done
	delete[] zombieArray;

	return 0;
}