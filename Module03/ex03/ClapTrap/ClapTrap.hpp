#include <iostream>
#include <string>

class ClapTrap
{
private:
    std::string _name;
    int _energyPoints;
    int _attackDamage;
    int _hitPoints;

public:
    ClapTrap();
    ClapTrap(std::string n);

    void attack(const std::string &target);
    void takeDamage(unsigned int amout);
    void beRepaired(unsigned int amout);
    

    std::string getName() const;
    int getEnery() const;
    int getAttack() const;
    int getHitpoints() const;
    ~ClapTrap();
};

