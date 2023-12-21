#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Constructor Harl here!" << std::endl;
	compLvl[0] = "DEBUG";
	compLvl[1] = "INFO";
	compLvl[2] = "WARNING";
	compLvl[3] = "ERROR";
}

Harl::~Harl(void)
{
	std::cout << "Destructor Harl here!" << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*functions[4])(void);
	functions[0] = &Harl::debug;
	functions[1] = &Harl::info;
	functions[2] = &Harl::warning;
	functions[3] = &Harl::error;
	for (int i = 0; i < 4; i++)
		if (this->compLvl[i] == level)
		{
			(this->*functions[i])();
			return;
		}
}

void Harl::debug(void)
{
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}