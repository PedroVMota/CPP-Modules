#include <string>
#include <iostream>
#include <math.h>

class Fixed
{
private:
    int _integer;
    static const int _const_integer = 8;
public:
    Fixed();
    Fixed(const Fixed &t);
    Fixed(const float &t);
    Fixed &operator=(const Fixed &other);
    int toInt();
    ~Fixed();
};

std::ostream operator<<(std::ostream &os, const Fixed &d);


