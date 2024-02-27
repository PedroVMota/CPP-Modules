#include "Ice.hpp"

Ice::Ice() : AMateria("Ice") {
    std::cout << "Ice default constructor called" << std::endl;
}
Ice::Ice(Ice const & src) : AMateria(src) {
    std::cout << "Ice copy constructor called" << std::endl;
}
Ice::~Ice() {
    std::cout << "Ice destructor called" << std::endl;
}

Ice & Ice::operator=(Ice const & src) {
    if (this != &src)
        AMateria::operator=(src);
    return *this;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
