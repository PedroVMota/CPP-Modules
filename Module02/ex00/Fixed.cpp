#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(/* args */)
{
    std::cout << "Default constructor called" << std::endl;
    _integer = 0;
}

/// @brief Copy Constructor
/// @param t 
Fixed::Fixed(const Fixed &t){
    std::cout << "Copy constructor called" << std::endl;
    _integer = t._integer;
}


Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
    {
        _integer = other._integer;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _integer = raw;
}

int Fixed::getRawBits(void)
{
    std::cout << "getRawBits member function called" << std::endl;
    return _integer;
}