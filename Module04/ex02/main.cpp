#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << dog->getType() << " says: " << std::endl;
	dog->makeSound();
	std::cout << cat->getType() << " says: " << std::endl;
	cat->makeSound();

	delete dog;
	delete cat;
}