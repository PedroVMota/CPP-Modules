#include "ClapTrap.hpp"

void ClapTrap::setEnergy(int n){
    _energyPoints = n;
}

void ClapTrap::setAttack(int n){
    _attackDamage = n;
}

void ClapTrap::setHitpoints(int n){
    _hitPoints = n;
}

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Construction called" << std::endl;
    _name = "Nameless";
    setEnergy(10);
    setAttack(10);
    setHitpoints(10);
}
ClapTrap::ClapTrap(std::string n) : _name(n){
    std::cout << "ClapTrap Construction called" << std::endl;
    setEnergy(10);
    setAttack(10);
    setHitpoints(10);
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap Assignation operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string &target){
    std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " Points of damage! " << std::endl; 
}

void ClapTrap::takeDamage(unsigned int amout){
    this->_hitPoints -= amout;
    std::cout << "ClapTrap " << _name << " take " << amout << " Points of damage! " << std::endl;
}
void ClapTrap::beRepaired(unsigned int amout)
{
    this->_hitPoints += amout;
    std::cout << "ClapTrap " << _name << " was repaired" << std::endl;
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
