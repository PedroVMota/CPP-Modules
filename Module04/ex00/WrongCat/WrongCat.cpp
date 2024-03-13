#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("Cat") {}

WrongCat::WrongCat(const std::string type) : WrongAnimal(type) {}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other.type) {}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  if (this == &other)
    return *this;
  this->setType(other.type);
  return *this;
}

void WrongCat::makeSound() const { std::cout << "WrongCat aoao" << std::endl; }

void WrongCat::setType(std::string type) { this->type = type; }

std::string WrongCat::getType() const { return this->type; }

WrongCat::~WrongCat() {}
