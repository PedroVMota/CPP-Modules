#include <iostream>
#include "ClapTrap.hpp"
#include <string>

class ScavTrap: public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string n);
    ScavTrap(const ScavTrap &other);
    ScavTrap& operator=(const ScavTrap &other);
    void guardGate();
    ~ScavTrap();
};

