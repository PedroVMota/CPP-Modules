#pragma once
#include <iostream>
#include <string>

class Weapon
{
private:
	std::string _type;

public:
	Weapon(std::string type);
	Weapon( void );
	const std::string &getType() const;
	void setType(const std::string &type);
};