#pragma once
#include <string>
#include <iostream>
// #include "ICharacter.hpp"

class AMateria
{
protected:
    std::string _type;
    long long _xpGiven;
    long long _xp;
public:
    AMateria();
    AMateria(std::string const &type);
    AMateria(const AMateria &other);
    virtual ~AMateria();
    AMateria &operator=(const AMateria &other);
    std::string const &getType() const;
    virtual AMateria *clone() const = 0;
    // virtual void use(ICharacter &target);
};