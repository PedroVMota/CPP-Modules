#include <ScavTrap.hpp>
#include <FragTrap.hpp>

int main (void)
{
    ClapTrap antonio = ClapTrap("Antonio");
    ClapTrap sergio = ClapTrap("Sergio");
    
    antonio.attack("Sergio");
    sergio.takeDamage(10);


    ScavTrap antonio2 = ScavTrap("Antonio");
    ScavTrap sergio2 = ScavTrap("Sergio");

    antonio2.attack("Sergio");
    sergio2.guardGate();
    sergio2.takeDamage(antonio2.getAttack());


    FragTrap antonio3 = FragTrap("Antonio");
    FragTrap sergio3 = FragTrap("Sergio");

    antonio3.attack("Sergio");
    sergio3.hightFivesGuys();

    sergio.beRepaired(10);


}