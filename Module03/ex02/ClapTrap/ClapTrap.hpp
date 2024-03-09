#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#include <string>

class ClapTrap
{
protected:
    std::string _name;
    int _energyPoints;
    int _attackDamage;
    int _hitPoints;
public:
    ClapTrap();
    ClapTrap(std::string n);
    ClapTrap(const ClapTrap &other);
    ClapTrap& operator=(const ClapTrap &other);
    void setEnergy(int n);
    void setAttack(int n);
    void setHitpoints(int n);
    int getEnery() const;
    int getAttack() const;
    int getHitpoints() const;
    void attack(const std::string &target);
    void takeDamage(unsigned int amout);
    void beRepaired(unsigned int amout);
    std::string getName() const;
    ~ClapTrap();
};

#endif