#include "Zombie.hpp"

int main(void)
{
	randomChump("Antonio Costa");
	randomChump("Andre Aventura");
	randomChump("Marcelo Rebelo");
	randomChump("Pacos coelhos.");
	Zombie *zombieNew = newZombie("loo");
	delete zombieNew;
	//comment the line 8 and execute with valgrind to see the leaks. 
}