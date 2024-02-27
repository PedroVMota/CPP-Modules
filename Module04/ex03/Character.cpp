#include "Character.hpp"

Character::Character() : _name("Default Mage")
{
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(std::string const &name) : _name(name)
{
    std::cout << "Character parameter constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(const Character &copy)
{
    std::cout << "Character copy constructor called" << std::endl;
    *this = copy;
}

Character &Character::operator=(const Character &copy)
{
    std::cout << "Character assignation operator called" << std::endl;
    if (this != &copy)
    {
        _name = copy._name;
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
                delete _inventory[i];
            if (copy._inventory[i])
                _inventory[i] = copy._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
}

std::string const &Character::getName() const
{
    return _name;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            return;
        }
    }
    std::cout << "Inventory is full" << std::endl;
    delete m;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3 || !_inventory[idx])
        return;
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 3 || !_inventory[idx])
        return;
    _inventory[idx]->use(target);
}
