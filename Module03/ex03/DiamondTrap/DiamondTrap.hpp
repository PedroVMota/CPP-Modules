#include <iostream>
#include <string>

class DiamondTrap
{
private:
    std::string _name;
    int _energyPoints;
    int _attackDamage;
    int _hitPoints;

public:
    DiamondTrap();
    DiamondTrap(std::string n);

    void attack(const std::string &target);
    void takeDamage(unsigned int amout);
    void beRepaired(unsigned int amout);

    void guardGate();

    std::string getName() const;
    int getEnery() const;
    int getAttack() const;
    int getHitpoints() const;
    ~DiamondTrap();
};

