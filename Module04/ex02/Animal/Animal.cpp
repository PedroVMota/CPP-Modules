#include "Animal.hpp"

Animal::Animal() : type("Animal"){
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type){
    std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type){
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other){
    std::cout << "Animal assignation operator called" << std::endl;
    if (this == &other)
        return *this;
    type = other.type;
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::setType(std::string type){
    this->type = type;
}

std::string Animal::getType() const{
    return type;
}
void Animal::makeSound() const
{
    std::cout << this->getType() << " doesn't make any sound" << std::endl;
}