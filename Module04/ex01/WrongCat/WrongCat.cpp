#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("Cat") { this->brain = new Brain(); }

WrongCat::WrongCat(const std::string type) : WrongAnimal(type) {
  this->brain = new Brain();
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other.type) {
  this->brain = new Brain(*other.brain);
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  if (this == &other)
    return *this;
  delete this->brain;
  this->brain = new Brain(*other.brain);
  this->setType(other.type);
  return *this;
}

void WrongCat::makeSound() const { std::cout << "WrongCat aoao" << std::endl; }

void WrongCat::setType(std::string type) { this->type = type; }

std::string WrongCat::getType() const { return this->type; }

WrongCat::~WrongCat() {}

void WrongCat::setNewIdea(int index, std::string idea) {
  this->brain->setIdea(index, idea);
}

std::string WrongCat::getIdea(int index) const {
  return this->brain->getIdea(index);
}
