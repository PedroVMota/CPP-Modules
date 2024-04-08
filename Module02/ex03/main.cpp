#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
    Point a = Point(2, 3);
    Point b = Point(4, 5);
    Point c = Point(6, 7);
    Point d = Point(11231, 1);

    if (bsp(a, b, c, d))
        std::cout << "Point d is inside the triangle abc" << std::endl;
    else
        std::cout << "Point d is outside the triangle abc" << std::endl;
    return 0;
}