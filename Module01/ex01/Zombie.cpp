#include "Zombie.hpp"

Zombie::Zombie() : _name("Unnamed") {}

Zombie::Zombie(std::string name) : _name(name){
	std::cout << "Zombie " << this->_name << " constructor here" << std::endl;
}
Zombie::~Zombie() {
	std::cout << "Zombie " << _name << " Deconstructor here" << std::endl;
}

void Zombie::announce(void){
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ...\n";
}

