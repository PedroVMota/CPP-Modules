#include <Cure.hpp>

Cure::Cure() : AMateria("Cure")
{
    std::cout << "Cure default constructor" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria("Cure")
{
    std::cout << "Cure copy constructor" << std::endl;
    *this = other;
}

Cure &Cure::operator=(const Cure &other)
{
    std::cout << "Cure Assignation Operator" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
        this->_xp = other._xp;
        this->_xpGiven = other._xpGiven;
    }
    return *this;
}

Cure::~Cure()
{
    std::cout << "Cure destructor" << std::endl;
}

AMateria *Cure::clone() const
{
    std::cout << "Cure clone" << std::endl;
    return new Cure(*this);
}

// virtual void Cure::use(ICharacter &target){
//     std::cout << "Cure used on " << target.getName() << std::endl;
//     this->_xp += this->_xpGiven;
//     std::cout << "* shoots an Cure bolt at " << target.getName() << " *" << std::endl;
//}