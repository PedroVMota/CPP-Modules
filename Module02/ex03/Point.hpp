
#include "Fixed.hpp"

class Point{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point(void);
		Point(const float &a, const float &b);
		Point(const Fixed &a, const Fixed &b);
		Point(const Point &other);
		Point &operator=(const Point &other);
		bool bsp( Point const a, Point const b, Point const c, Point const point);
		~Point();

		int getX(void) const;
		int getY(void) const;
		
};

std::ostream& operator<<( std::ostream& os, const Point& fixed );
