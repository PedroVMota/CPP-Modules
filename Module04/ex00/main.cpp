#include "Animal/Animal.hpp"
#include "Cat/Cat.hpp"
#include "Dog/Dog.hpp"
#include "WrongCat/WrongCat.hpp"
#include <iostream>

int main() {
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  std::cout << std::endl << "======= TYPE ======" << std::endl;
  std::cout << meta->getType() << " " << std::endl;
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;

  std::cout << std::endl << "======= Make Sound Function ======" << std::endl;
  j->makeSound(); // will output the cat sound!
  i->makeSound();
  meta->makeSound(); // is not a dog not even a cat so the function should print
                     // something tell us that he can't make any sound

  std::cout << "=========== WRONG ANIMAL =========\n";
  WrongAnimal *wrongCat = new WrongCat();
  Cat *kitty = new Cat();
  wrongCat->makeSound();
  kitty->makeSound();

  std::cout << std::endl << "======= Deconstructors ======" << std::endl;
  delete wrongCat;
  delete kitty;
  delete meta;
  delete j;
  delete i;
}
