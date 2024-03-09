#include <iostream>
#include <string>
#include <ClapTrap.hpp>

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string n);
    FragTrap &operator=(const FragTrap &frag);
    FragTrap(const FragTrap &frag);
    ~FragTrap();
    void hightFivesGuys();
};

