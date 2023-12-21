#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Constructor Harl here!" << std::endl;
	compLvl[0] = "DEBUG";
	compLvl[1] = "INFO";
	compLvl[2] = "WARNING";
	compLvl[3] = "ERROR";
	compLvl[4] = "OTHER";
}

Harl::~Harl(void)
{
	std::cout << "Destructor Harl here!" << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*functions[5])(void);
	functions[0] = &Harl::debug;
	functions[1] = &Harl::info;
	functions[2] = &Harl::warning;
	functions[3] = &Harl::error;
	functions[4] = &Harl::other;
	for (int i = 0; i < 4; i++)
		if (this->compLvl[i] == level)
		{
			(this->*functions[i])();
			return;
		}
	(this->*functions[4])();
	return;
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "[ I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do! ] " << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "[ I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more! ]" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "[ I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month. ]" << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "[ This is unacceptable! I want to speak to the manager now. ]" << std::endl;
}

void Harl::other(void)
{
	std::cout << "[ Probably complaining about insignificant problem ]" << std::endl;
}

