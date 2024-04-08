#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _rawBi(0)
{
}


Fixed::Fixed(const Fixed &t): _rawBi(t._rawBi){
}

Fixed::Fixed(const float &t) : _rawBi(roundf(t * (1 << this->_bitShift)))
{
}

Fixed::Fixed(const int &t) : _rawBi(t << _bitShift)
{
}


Fixed &Fixed::operator=(const Fixed &other) {
    if(this != &other)
        _rawBi = other._rawBi;
    return *this;
}

Fixed::~Fixed()
{
}

void	Fixed::setRawBits( int const raw ) {
	_rawBi = raw;
}

int		Fixed::getRawBits( void ) {
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