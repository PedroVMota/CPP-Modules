#include <iostream>
#include <string>

class ScavTrap
{
private:
    std::string _name;
    int _energyPoints;
    int _attackDamage;
    int _hitPoints;

public:
    ScavTrap();
    ScavTrap(std::string n);

    void attack(const std::string &target);
    void takeDamage(unsigned int amout);
    void beRepaired(unsigned int amout);

    void guardGate();

    std::string getName() const;
    int getEnery() const;
    int getAttack() const;
    int getHitpoints() const;
    ~ScavTrap();
};

