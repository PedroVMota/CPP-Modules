#include "AMateria.hpp"

// Constructors and destructors
AMateria::AMateria(void) : _type("default") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria &copy) : _type(copy._type) {}

AMateria::~AMateria(void) {}

// Operators

AMateria &AMateria::operator=(const AMateria &copy)
{
    if (this == &copy)
        return (*this);
    _type = copy._type;
    return (*this);
}

std::string const &AMateria::getType(void) const
{
    return (_type);
}

void AMateria::use(ICharacter &target)
{
    (void)target;
    return;
}

