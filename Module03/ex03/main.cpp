#include <DiamondTrap.hpp>

int main (void)
{
    ClapTrap clap("Clap");
    ScavTrap scav("Scav");
    FragTrap frag("Frag");
    DiamondTrap diam("Diam");

    clap.attack("enemy");
    scav.attack("enemy");
    frag.attack("enemy");
    diam.attack("enemy");

    clap.beRepaired(100);
    scav.guardGate();
    frag.hightFivesGuys();
    diam.whoAmI();

}