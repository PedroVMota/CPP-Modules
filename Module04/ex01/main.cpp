#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int n = 4;
	Animal *wild[n];

	for (int i = 0; i < n; i++)
		(i < (n/2)) ? wild[i] = new Dog() : wild[i] = new Cat();
	for(int i = 0; i < n; i++)
		wild[i]->makeSound();
	for(int i = 0; i < n; i++)
		delete wild[i];

	std::cout << std::endl << "========== COPY TEST ============" << std::endl;
	Animal *deepCopy = new Dog();
	deepCopy->makeSound();
	//Test Shallow Copy
	Animal *shallowCopy = new Cat();
	*shallowCopy = *deepCopy;
	shallowCopy->makeSound();

	//Teste destrutores
	delete deepCopy;
	delete shallowCopy;
}