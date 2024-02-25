#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Default Constructor" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Dog type constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (&other != this)
        return *this;
    this->type = other.getType();
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Defualt Deconstructor" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << this->getType() << " Barks" << std::endl;
}
