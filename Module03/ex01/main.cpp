#include <ClapTrap.hpp>

int main (void)
{
    ClapTrap antonio = ClapTrap("Antonio");
    ClapTrap sergio = ClapTrap("Sergio");
    
    antonio.attack("Sergio");
    sergio.takeDamage(10);
}