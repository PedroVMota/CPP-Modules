#include "Weapon.hpp"

Weapon::Weapon(void) : _type("IMORTAL"){};
Weapon::Weapon(std::string newType) { _type = newType; };
void Weapon::setType(const std::string &type)
{
    _type = type;
}
const std::string &Weapon::getType(void) const
{
    return _type;
};