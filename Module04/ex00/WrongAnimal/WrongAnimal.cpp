#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("Cat") {}

WrongAnimal::WrongAnimal(std::string type) : type(type) {}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  if (this == &other)
    return *this;
  this->type = other.type;
  return *this;
}
WrongAnimal::~WrongAnimal() {}

void WrongAnimal::makeSound() const {
  std::cout << "wrongAnimal sound" << std::endl;
}

void WrongAnimal::setType(std::string type) { this->type = type; }

std::string WrongAnimal::getType() const { return this->type; }
