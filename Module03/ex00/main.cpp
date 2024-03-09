#include "ClapTrap.hpp"

int main (void)
{
    ClapTrap antonio = ClapTrap("Antonio");
    ClapTrap sergio = ClapTrap("Sergio");
    ClapTrap antonioto(antonio);
    
    antonio.attack("Sergio");
    sergio.takeDamage(10);
    antonioto.beRepaired(10);
}