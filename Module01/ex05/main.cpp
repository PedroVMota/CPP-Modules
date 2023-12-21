#include "Harl.hpp"

int main(void)
{
	Harl client;
	client.complain("DEBUG");
	client.complain("INFO");
	client.complain("WARNING");
	client.complain("ERROR");
	return 0;
}