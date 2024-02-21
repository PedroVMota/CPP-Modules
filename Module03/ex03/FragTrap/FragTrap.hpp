#include <iostream>
#include <string>
#include <ClapTrap.hpp>

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string n);
    FragTrap &operator=(const FragTrap &frag);
    ~FragTrap();
    void hightFivesGuys();
};

