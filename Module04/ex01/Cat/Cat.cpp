#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat"){
  this->brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type){
  this->brain = new Brain();
}

Cat &Cat::operator=(const Cat &other){
  if (this == &other)
    return *this;
  this->setType(other.getType());
  *this->brain = *other.brain;
  return *this;
}

void Cat::makeSound() const{
  std::cout << this->getType() << " meows" << std::endl;
}

Cat::~Cat(){
  delete this->brain;
}

void Cat::setNewIdea(int index, std::string idea){
  this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const{
  return this->brain->getIdea(index);
}