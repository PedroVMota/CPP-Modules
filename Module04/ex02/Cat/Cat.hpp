#include "../Animal/Animal.hpp"
#include "../Brain/Brain.hpp"

class Cat : virtual public Animal
{
private:
  Brain *brain;

public:
  Cat();
  Cat(std::string type);
  Cat &operator=(const Cat &other);
  virtual ~Cat();
  void makeSound() const;
  virtual void setNewIdea(int index, std::string idea);
  virtual std::string getIdea(int index) const;
};
