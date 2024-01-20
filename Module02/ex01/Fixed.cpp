#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _rawBi(0)
{
    std::cout << "Default constructor called" << std::endl;
}


/// @brief Copy Constructor
/// @param t 
Fixed::Fixed(const Fixed &t): _rawBi(t._rawBi){
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const float &t) : _rawBi(roundf(t * (1 << this->_bitShift)))
{
    std::cout << "Fixed Float Constructor called" << std::endl;
}

Fixed::Fixed(const int &t) : _rawBi(t << _bitShift)
{
    std::cout << "Fixed Float Constructor called" << std::endl;
}


Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
        _rawBi = other._rawBi;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits( int const raw ) {
	_rawBi = raw;
}

int		Fixed::getRawBits( void ) {
	std::cout << "getRawBits member function called\n";
	return ( _rawBi );
}

float 	Fixed::toFloat( void ) const {
	return ( _rawBi / (float)(1 << _bitShift) );
}

int 	Fixed::toInt( void ) const {
	return ( _rawBi >> _bitShift );
}

std::ostream& operator<<( std::ostream& os, const Fixed& fixed ) {
	os << fixed.toFloat();
	return os;
}