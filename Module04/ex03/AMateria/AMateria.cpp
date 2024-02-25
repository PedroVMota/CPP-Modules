#include "AMateria.hpp"

AMateria::AMateria() : _type("default"), _xpGiven(0), _xp(0)
{
    std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type), _xpGiven(0), _xp(0){
    std::cout << "AMateria type constructor" << std::endl;
};

AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout << "AMateria Assignation Operator" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
        this->_xp = other._xp;
        this->_xpGiven = other._xpGiven;
    }
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor" << std::endl;
}

std::string const &AMateria::getType() const
{
    return this->_type;
}

// void AMateria::use(ICharacter &target)
// {
//     std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;
//     this->_xp += this->_xpGiven;

//     if(this->_type == "ice")
//         std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
//     else if(this->_type == "cure")
//         std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
// }



