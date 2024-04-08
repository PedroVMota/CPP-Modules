
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

		float getX(void) const;
		float getY(void) const;
		
};