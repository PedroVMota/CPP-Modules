#include "Point.hpp"

Point::Point(void) : _x(0), _y(0){};
Point::Point(const float &a, const float &b) : _x(a), _y(b){};
Point::Point(const Fixed &a, const Fixed &b) : _x(a), _y(b){};
Point::Point(const Point &other) : _x(other._x), _y(other._y){};

Point &Point::operator=(const Point &other)
{
	if (this != &other) // protect against invalid self-assignment
	{
		(Fixed &)this->_x = other._x;
		(Fixed &)this->_y = other._y;
	}
	// by convention, always return *this
	return *this;
}

float Point::getX(void) const
{
	return this->_x.toFloat();
}

float Point::getY(void) const
{
	return this->_y.toFloat();
}

Point::~Point(){};
