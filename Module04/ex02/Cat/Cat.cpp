#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Default Constructor" << std::endl;
    this->brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << "Cat type constructor" << std::endl;
    this->brain = new Brain();
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat Assignation Operator" << std::endl;
    if (this == &other)
        return *this;
    this->setType(other.getType());
    *this->brain = *other.brain;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << this->getType() << " meows" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Defualt Deconstructor" << std::endl;
    delete this->brain;
}