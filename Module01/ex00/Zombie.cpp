#include "Zombie.hpp"

Zombie::Zombie() : _name("Unnamed") {}

Zombie::Zombie(std::string name) : _name(name){
	std::cout << "\e[0;32m" <<  "Zombie " << this->_name << " constructor here" << "\e[0m" << std::endl;
}
Zombie::~Zombie() {
	std::cout << "\e[1;31m" << "Zombie " << _name << " Deconstructor here" << "\e[0m" << std::endl;
}

void Zombie::announce(void){
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ...\n";
}

