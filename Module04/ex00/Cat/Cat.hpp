#include <Animal.hpp>

class Cat : virtual public Animal
{
public:
    Cat();
    Cat(std::string type);
    Cat &operator=(const Cat &other);
    virtual ~Cat();
    void makeSound() const;
};