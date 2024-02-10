#include "ClapTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap Construction called" << std::endl;
    _name = "Nameless";
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 10;

}
ScavTrap::ScavTrap(std::string n) : _name(n){
    std::cout << "ScavTrap Construction called" << std::endl;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 10;
}


void ScavTrap::attack(const std::string &target){
    std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " Points of damage! " << std::endl; 
}

void ScavTrap::takeDamage(unsigned int amout){
    if(this->_hitPoints - amout >= 0)
        this->_hitPoints -= amout;
    else
        this->_hitPoints = 0;
    std::cout << "TakeDamage function was called" << std::endl;
}
void ScavTrap::beRepaired(unsigned int amout)
{
    if(this->_hitPoints + amout <= 10)
        this->_hitPoints += amout;
    else
        this->_hitPoints = 10;
    std::cout << "beRepaired function was called" << std::endl;
}

void ScavTrap::guardGate(){
    
}

std::string ScavTrap::getName() const{
    return _name;
}
int ScavTrap::getEnery() const{
    return _energyPoints;
}
int ScavTrap::getAttack() const{
    return _attackDamage;
}
int ScavTrap::getHitpoints() const{
    return _hitPoints;
}


ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Deconstruction called" << std::endl;
}
