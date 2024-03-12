#include "../Animal/Animal.hpp"
#include "../Brain/Brain.hpp"
class Dog : virtual public Animal
{
private:
    Brain *brain;
public:
    Dog();
    Dog(std::string type);
    Dog &operator=(const Dog &other);
    virtual void setNewIdea(int index, std::string idea);
    virtual std::string getIdea(int index) const;
    virtual ~Dog();
    virtual void makeSound() const;

};