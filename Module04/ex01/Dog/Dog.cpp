#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog D Constructor" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Dog type constructor" << std::endl;
    this->brain = new Brain();
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog Assignation Operator" << std::endl;
    if (this == &other)
        return *this;
    this->setType(other.getType());
    *this->brain = *other.brain;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Default Deconstructor" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const
{
    std::cout << this->getType() << " Barks" << std::endl;
}
