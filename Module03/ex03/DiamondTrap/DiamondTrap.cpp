#include <DiamondTrap.hpp>

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diam)
{
    if (this == &diam)
        return (*this);
    this->_name = diam._name;
    this->_name = diam._name;
    this->_energyPoints = diam._energyPoints;
    this->_attackDamage = diam._attackDamage;
    return (*this);
}

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diam) : ClapTrap(diam), FragTrap(diam), ScavTrap(diam)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = diam;
}

DiamondTrap::DiamondTrap(std::string n) : ClapTrap(n + "_clap_name"), FragTrap(n), ScavTrap(n)
{
    std::cout << "DiamondTrap name constructor called" << std::endl;
    FragTrap::_hitPoints = 100;
    FragTrap::_energyPoints = 30;
    setEnergy(ScavTrap::_energyPoints);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << getName() << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}

