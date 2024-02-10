#include "Point.hpp"

float triangleFormula(Point p1, Point p2, Point p3)
{
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

/// @brief Check if a point is inside a triangle
/// @param a first point of the triangle
/// @param b second point of the triangle
/// @param c third point of the triangle
/// @param point point to check
/// @return true is is inside, false otherwise
bool bsp(Point const a, Point const b, Point const c, Point const point){
    float d1, d2, d3;
    bool has_neg, has_pos;

    d1 = triangleFormula(point, a, b);
    d2 = triangleFormula(point, b, c);
    d3 = triangleFormula(point, c, a);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}