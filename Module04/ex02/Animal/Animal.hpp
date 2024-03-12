#pragma once
#include "../Brain/Brain.hpp"
#include <string>

class Animal {
protected:
  std::string type;
  Brain *brain;

public:
  Animal();
  Animal(std::string type);
  Animal(const Animal &other);
  Animal &operator=(const Animal &other);
  virtual ~Animal();

  void setType(std::string type);
  std::string getType() const;
  virtual void makeSound() const = 0; // from now on Animal is an abstract class
  virtual void setNewIdea(int index, std::string idea);
  virtual std::string getIdea(int index) const;
};
