#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
    Point a = Point(0, 0);
    Point b = Point(5, 1.5);
    Point c = Point(0, 3);
    Point d = Point(0, 4);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    if (bsp(a, b, c, d))
        std::cout << "Point d is inside the triangle abc" << std::endl;
    else
        std::cout << "Point d is outside the triangle abc" << std::endl;
    return 0;
}