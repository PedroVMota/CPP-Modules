#include <Ice.hpp>

Ice::Ice() : AMateria("Ice")
{
    std::cout << "Ice default constructor" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria("Ice")
{
    std::cout << "Ice copy constructor" << std::endl;
    *this = other;
}

Ice &Ice::operator=(const Ice &other)
{
    std::cout << "Ice Assignation Operator" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
        this->_xp = other._xp;
        this->_xpGiven = other._xpGiven;
    }
    return *this;
}

Ice::~Ice()
{
    std::cout << "Ice destructor" << std::endl;
}

AMateria *Ice::clone() const
{
    std::cout << "Ice clone" << std::endl;
    return new Ice(*this);
}

// virtual void Ice::use(ICharacter &target){
//     std::cout << "Ice used on " << target.getName() << std::endl;
//     this->_xp += this->_xpGiven;
//     std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
//}