#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    setEnergy(100);
    setAttack(30);
}

FragTrap::FragTrap(std::string n) : ClapTrap(n)
{
    std::cout << "FragTrap constructor called" << std::endl;
    setEnergy(100);
    setAttack(30);
}

FragTrap::FragTrap(const FragTrap &frag) : ClapTrap(frag)
{
    std::cout << "Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &frag)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &frag)
    {
        this->_name = frag._name;
        this->_hitPoints = frag._hitPoints;
        this->_energyPoints = frag._energyPoints;
        this->_attackDamage = frag._attackDamage;
    }
    return *this;
}

void FragTrap::hightFivesGuys()
{
    std::cout << "FragTrap " << getName() << " has entered in high five mode" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Deconstruction called" << std::endl;
}


