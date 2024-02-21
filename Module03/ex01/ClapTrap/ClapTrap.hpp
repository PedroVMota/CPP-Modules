#include <iostream>
#include <string>

class ClapTrap
{
protected:
    std::string _name;
    int _energyPoints;
    int _attackDamage;
    int _hitPoints;
    void setEnergy(int n);
    void setAttack(int n);
    void setHitpoints(int n);

public:
    ClapTrap();
    ClapTrap(std::string n);
    ClapTrap& operator=(const ClapTrap &other);
    int getEnery() const;
    int getAttack() const;
    int getHitpoints() const;
    void attack(const std::string &target);
    void takeDamage(unsigned int amout);
    void beRepaired(unsigned int amout);
    std::string getName() const;
    ~ClapTrap();
};

