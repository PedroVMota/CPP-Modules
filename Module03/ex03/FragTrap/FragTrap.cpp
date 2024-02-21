#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap Construction called" << std::endl;
    _name = "Nameless";
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;

}
FragTrap::FragTrap(std::string n) : _name(n){
    std::cout << "FragTrap Construction called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;

}


void FragTrap::attack(const std::string &target){
    std::cout << "FragTrap " << _name << " attacks " << target << " causing " << _attackDamage << " Points of damage! " << std::endl; 
}

void FragTrap::takeDamage(unsigned int amout){
    if((int)this->_hitPoints - (int)amout > 0)
        this->_hitPoints -= amout;
    else
        this->_hitPoints = 0;
    std::cout << "TakeDamage function was called" << std::endl;
}
void FragTrap::beRepaired(unsigned int amout)
{
    if(this->_hitPoints + amout <= 10)
        this->_hitPoints += amout;
    else
        this->_hitPoints = 10;
    std::cout << "beRepaired function was called" << std::endl;
}

std::string FragTrap::getName() const{
    return _name;
}
int FragTrap::getEnery() const{
    return _energyPoints;
}
int FragTrap::getAttack() const{
    return _attackDamage;
}
int FragTrap::getHitpoints() const{
    return _hitPoints;
}

void FragTrap::hightFivesGuys(){
    std::cout << "FragTrap " << _name << " has entered in high five mode" << std::endl;
}


FragTrap::~FragTrap()
{
    std::cout << "FragTrap Deconstruction called" << std::endl;
}
