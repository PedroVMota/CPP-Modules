#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}
HumanB::HumanB(std::string name, Weapon &weapon) : _name(name), _weapon(&weapon) {}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

std::string HumanB::getType() const
{
    if (_weapon)
        return _weapon->getType();
    else
        return "";
}

void HumanB::attack() const
{
    if(!_weapon)
        std::cout << _name << " Can attack without nothing" << std::endl;
    else
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}