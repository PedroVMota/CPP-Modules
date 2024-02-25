#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Default Constructor" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << "Cat type constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (&other != this)
        return *this;
    this->type = other.getType();
    return *this;
}

void Cat::makeSound() const
{
    std::cout << this->getType() << " meows" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Defualt Deconstructor" << std::endl;
}