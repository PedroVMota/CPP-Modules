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

int		Fixed::getRawBits(void) const {
	return ( _rawBi );
}

float 	Fixed::toFloat( void ) const {
	return ( _rawBi / (float)(1 << _bitShift) );
}

int 	Fixed::toInt( void ) const {
	return ( _rawBi >> _bitShift );
}

Fixed Fixed::operator+(const Fixed &other) {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) {
    return Fixed(this->toFloat() / other.toFloat());
}

bool Fixed::operator>(const Fixed &other) {
    return this->toFloat() > other.toFloat();
}

bool Fixed::operator<(const Fixed &other) {
    return this->toFloat() < other.toFloat();
}

bool Fixed::operator>=(const Fixed &other) {
    return this->toFloat() >= other.toFloat();
}

bool Fixed::operator<=(const Fixed &other) {
    return this->toFloat() <= other.toFloat();
}

bool Fixed::operator==(const Fixed &other) {
    return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed &other) {
    return this->toFloat() != other.toFloat();
}

Fixed &Fixed::operator++() {
    _rawBi++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--() {
    _rawBi--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {

    if(a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {

    if(a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    
        if(a.getRawBits() > b.getRawBits())
            return a;
        return b;
}

//xwayland

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if(a.getRawBits() > b.getRawBits())
        return a;
    return b;
}


std::ostream& operator<<( std::ostream& os, const Fixed& fixed ) {
	os << fixed.toFloat();
	return os;
}