#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal") { this->brain = new Brain(); }

Animal::Animal(std::string type) : type(type) { this->brain = new Brain(); }

Animal::Animal(const Animal &other) : type(other.type) {
  this->brain = new Brain(*other.brain);
}

Animal &Animal::operator=(const Animal &other) {
  if (this == &other)
    return *this;
  type = other.type;
  this->brain = new Brain(*other.brain);
  return *this;
}

Animal::~Animal() { delete this->brain; }

void Animal::setType(std::string type) { this->type = type; }

std::string Animal::getType() const { return type; }

void Animal::setNewIdea(int index, std::string idea) {
  this->brain->setIdea(index, idea);
}

std::string Animal::getIdea(int index) const {
  return this->brain->getIdea(index);
}
