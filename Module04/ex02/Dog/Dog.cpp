#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
    this->brain = new Brain();
}

Dog::Dog(std::string type) : Animal(type){
    this->brain = new Brain();
}

Dog &Dog::operator=(const Dog &other)
{
    if (this == &other)
        return *this;
    this->setType(other.getType());
    *this->brain = *other.brain;
    return *this;
}

Dog::~Dog(){
    delete this->brain;
}

void Dog::makeSound() const{
    std::cout << this->getType() << " Barks" << std::endl;
}

void Dog::setNewIdea(int index, std::string idea){
    this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const{
    return this->brain->getIdea(index);
}