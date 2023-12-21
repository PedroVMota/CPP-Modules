#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl client;
	if(ac == 2)
		client.complain(av[1]);
	return 0;
}