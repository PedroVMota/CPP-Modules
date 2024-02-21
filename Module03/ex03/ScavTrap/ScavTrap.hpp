#include <iostream>
#include "ClapTrap.hpp"
#include <string>

class ScavTrap: virtual public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string n);
    ScavTrap& operator=(const ScavTrap &other);
    void guardGate();
    ~ScavTrap();
};

