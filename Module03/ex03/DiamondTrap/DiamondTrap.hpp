#include <iostream>
#include <string>
#include <FragTrap.hpp>
#include <ScavTrap.hpp>


/*
    Virtual Keyword
    When a class is derived from multiple classes, 
    the derived class inherits all the members of the base classes.

    In other words, just make a "Copy of the class" and put it in the derived class.
*/

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap
{
    public:
        DiamondTrap();
        DiamondTrap(std::string n);
        DiamondTrap(const DiamondTrap &diam);
        DiamondTrap &operator=(const DiamondTrap &diam);
        ~DiamondTrap();
        void whoAmI();
};

