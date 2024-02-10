#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Construction called" << std::endl;
    _name = "Nameless";
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 10;

}
ClapTrap::ClapTrap(std::string n) : _name(n){
    std::cout << "ClapTrap Construction called" << std::endl;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 10;
}


void ClapTrap::attack(const std::string &target){
    std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " Points of damage! " << std::endl; 
}

void ClapTrap::takeDamage(unsigned int amout){
    if(this->_hitPoints - amout >= 0)
        this->_hitPoints -= amout;
    else
        this->_hitPoints = 0;
    std::cout << "TakeDamage function was called" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amout)
{
    if(this->_hitPoints + amout <= 10)
        this->_hitPoints += amout;
    else
        this->_hitPoints = 10;
    std::cout << "beRepaired function was called" << std::endl;
}

std::string ClapTrap::getName() const{
    return _name;
}
int ClapTrap::getEnery() const{
    return _energyPoints;
}
int ClapTrap::getAttack() const{
    return _attackDamage;
}
int ClapTrap::getHitpoints() const{
    return _hitPoints;
}


ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Deconstruction called" << std::endl;
}
