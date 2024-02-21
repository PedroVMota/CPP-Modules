#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
    std::cout << "ScavTrap Construction called" << std::endl;
    setEnergy(50);
    setAttack(20);
}

ScavTrap::ScavTrap(std::string n) : ClapTrap(n){
    std::cout << "ScavTrap Construction called" << std::endl;
    setEnergy(50);
    setAttack(20);
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << getName() << " has entered in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Deconstruction called" << std::endl;
}
