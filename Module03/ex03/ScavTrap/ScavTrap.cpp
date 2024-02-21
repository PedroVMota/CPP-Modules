#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap Construction called" << std::endl;
    _name = "Nameless";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;

}
ScavTrap::ScavTrap(std::string n) : _name(n){
    std::cout << "ScavTrap Construction called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}


void ScavTrap::attack(const std::string &target){
    std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " Points of damage! " << std::endl; 
}

void ScavTrap::takeDamage(unsigned int amout){
    if((int)this->_hitPoints - (int)amout >= 0)
        this->_hitPoints -= amout;
    else
        this->_hitPoints = 0;
    std::cout << "ScavTrap " << _name << " take " << amout << " Points of damage! " << std::endl;
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
    std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode" << std::endl;
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
