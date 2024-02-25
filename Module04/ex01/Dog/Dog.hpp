#include <Animal.hpp>


class Dog : virtual public Animal
{
private:
    Brain *brain;
public:
    Dog();
    Dog(std::string type);
    Dog &operator=(const Dog &other);
    virtual ~Dog();
    virtual void makeSound() const;
};