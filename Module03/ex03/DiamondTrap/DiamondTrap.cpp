#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap Construction called" << std::endl;
    _name = "Nameless";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;

}
DiamondTrap::DiamondTrap(std::string n) : _name(n){
    std::cout << "DiamondTrap Construction called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}


void DiamondTrap::attack(const std::string &target){
    std::cout << "DiamondTrap " << _name << " attacks " << target << " causing " << _attackDamage << " Points of damage! " << std::endl; 
}

void DiamondTrap::takeDamage(unsigned int amout){
    if((int)this->_hitPoints - (int)amout >= 0)
        this->_hitPoints -= amout;
    else
        this->_hitPoints = 0;
    std::cout << "DiamondTrap " << _name << " take " << amout << " Points of damage! " << std::endl;
}
void DiamondTrap::beRepaired(unsigned int amout)
{
    if(this->_hitPoints + amout <= 10)
        this->_hitPoints += amout;
    else
        this->_hitPoints = 10;
    std::cout << "beRepaired function was called" << std::endl;
}

void DiamondTrap::guardGate(){
    std::cout << "DiamondTrap " << _name << " has entered in Gate keeper mode" << std::endl;
}

std::string DiamondTrap::getName() const{
    return _name;
}
int DiamondTrap::getEnery() const{
    return _energyPoints;
}
int DiamondTrap::getAttack() const{
    return _attackDamage;
}
int DiamondTrap::getHitpoints() const{
    return _hitPoints;
}


DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Deconstruction called" << std::endl;
}
