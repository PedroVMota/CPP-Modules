#include <Animal.hpp>
#include <Brain.hpp>

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
};