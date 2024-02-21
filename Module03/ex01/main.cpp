#include <ScavTrap.hpp>


int main (void)
{
    ClapTrap antonio = ClapTrap("Antonio");
    ScavTrap antonio2 = ScavTrap("Antonio");
    ScavTrap AntonioClone;


    AntonioClone = antonio2;
    AntonioClone.guardGate();
}