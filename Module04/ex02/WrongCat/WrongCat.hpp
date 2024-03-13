#pragma once
#include "../Brain/Brain.hpp"
#include "../WrongAnimal/WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal {
protected:
  std::string type;
  Brain *brain;

public:
  WrongCat();
  WrongCat(std::string type);
  WrongCat(const WrongCat &other);
  WrongCat &operator=(const WrongCat &other);
  virtual ~WrongCat();

  void setType(std::string type);
  std::string getType() const;
  void makeSound() const;

  virtual void setNewIdea(int index, std::string idea);
  virtual std::string getIdea(int index) const;
};
