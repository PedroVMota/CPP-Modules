
#include "Animal/Animal.hpp"
#include "Cat/Cat.hpp"
#include "Dog/Dog.hpp"
#include "WrongCat/WrongCat.hpp"

/*
 * This main make the program compile
 */
int main() {

  std::cout << "-------- TEST THAT WORK -----------" << std::endl;
  int arrCapacity = 20;

  Animal **array = new Animal *[arrCapacity];
  for (int i = 0; i < arrCapacity; i++) {
    if (i % 2 == 0)
      array[i] = new Dog();
    else
      array[i] = new Cat();
    array[i]->makeSound();
    delete array[i];
  }
  delete[] array;

  return 0;
}

/*
 * This main make the program not compile

int main() {

  std::cout << "-------- TEST THAT WORK -----------" << std::endl;
  int arrCapacity = 20;

  Animal **array = new Animal *[arrCapacity];
  for (int i = 0; i < arrCapacity; i++) {
    if (i % 2 == 0)
      array[i] = new Dog();
    else if (i % 3 == 0)
      array[i] = new Animal();
    else
      array[i] = new Cat();
    array[i]->makeSound();
    delete array[i];
  }
  delete[] array;

  return 0;
}

*/
