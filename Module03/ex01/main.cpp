#include <ScavTrap.hpp>


int main (void)
{
    ClapTrap clap("Clap");
    ScavTrap scav("Scav");

    ClapTrap ClapClone(clap);
    ScavTrap ScavClone(scav);

    clap.attack("enemy");
    scav.attack("enemy");

    ClapClone.beRepaired(10);
    ScavClone.beRepaired(10);

}