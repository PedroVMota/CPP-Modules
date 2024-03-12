
#include "../Animal/Animal.hpp"
#include "../Brain/Brain.hpp"
#include "../Dog/Dog.hpp"
#include "../Cat/Cat.hpp"

int main()
{

	std::cout << "-------- TEST THAT WORK -----------" << std::endl;
	int arrCapacity = 20;
	Animal **array = new Animal *[arrCapacity];
	for (int i = 0; i < arrCapacity; i++)
	{
		if (i % 2 == 0)
			array[i] = new Dog();
		else
			array[i] = new Cat();
		array[i]->makeSound();
		delete array[i];
	}
	delete[] array;

	std::cout << "-------- TEST THAT JUST DON'T WORK -----------" << std::endl;
	{
		Animal dog = Dog();
		Animal cat = Cat();
		dog.makeSound();
		cat.makeSound();
	}
	std::cout << "-------- SAME TEST BUT WORKING -----------" << std::endl;
	{
		/*
			In the first block, you're creating Dog and Cat objects and assigning them to Animal variables. This is known as "object slicing". The Dog and Cat objects are being sliced down to Animal objects, and any methods that are overridden in the Dog and Cat classes will not be called. Instead, the Animal version of the method will be called.

			In the second block, you're creating pointers to Animal objects and assigning them to new Dog and Cat objects. This allows the Dog and Cat objects to maintain their identity, and the overridden methods in the Dog and Cat classes will be called. This is polymorphism in action.
			
			In C++, if you want to take advantage of polymorphism, you should use pointers or references to base class objects.
		*/
		Animal *dog = new Dog();
		Animal *cat = new Cat();
		dog->makeSound();
		cat->makeSound();
		delete dog;
		delete cat;
	}

	std::cout << "-------- BRAIN TESTS ---------" << std::endl;
	{
		Animal *dog = new Dog();
		Animal *cat = new Cat();
		dog->setNewIdea(2, "I am a dog");
		cat->setNewIdea(0, "I am a cat");

		std::cout << "Dog Idea: " << (dog->getIdea(0).length() != 0 ? dog->getIdea(0) : "Empty") << std::endl;
		std::cout << "Cat Idea: " << (cat->getIdea(0).length() != 0 ? cat->getIdea(0) : "Empty") << std::endl;
		std::cout << "Dog Idea: " << (dog->getIdea(2).length() != 0 ? dog->getIdea(2) : "Empty") << std::endl;
		std::cout << "Cat Idea: " << (cat->getIdea(2).length() != 0 ? cat->getIdea(2) : "Empty") << std::endl;

		delete dog;
		delete cat;

		Animal teste = Dog();
		teste.setNewIdea(0, "CHECKING IF IT WORKS");
		Animal teste2 = teste;
		std::cout << "Dog Idea: " << (teste2.getIdea(0).length() != 0 ? teste2.getIdea(0) : "Empty") << std::endl;
	}
	return 0;
}