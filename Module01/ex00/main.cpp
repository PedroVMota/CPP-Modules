#include "Zombie.hpp"

int main(void)
{
	randomChump("Andre Aventura");
	randomChump("Andre Aventura");
	randomChump("Marcelo Rebelo");
	randomChump("Pacos coelhos.");
	Zombie *zombieNew = newZombie("loo");
	delete zombieNew;
}