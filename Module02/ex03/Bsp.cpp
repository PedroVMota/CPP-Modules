#include "Point.hpp"

/// @brief Check if a point is inside a triangle
/// @param a first point of the triangle
/// @param b second point of the triangle
/// @param c third point of the triangle
/// @param point point to check
/// @return true is is inside, false otherwise
bool bsp(Point const a, Point const b, Point const c, Point const point){
    double area = 0.5 * (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));
    double area1 = 0.5 * (point.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - point.getY()) + c.getX() * (point.getY() - b.getY()));
    double area2 = 0.5 * (a.getX() * (point.getY() - c.getY()) + point.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - point.getY()));
    double area3 = 0.5 * (a.getX() * (b.getY() - point.getY()) + b.getX() * (point.getY() - a.getY()) + point.getX() * (a.getY() - b.getY()));
    double epsilon = 1e-10; // tolerance value
    if (std::fabs(area - (area1 + area2 + area3)) < epsilon)
        return true;
    return false;
}