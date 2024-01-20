#include <string>
#include <iostream>
#include <math.h>

class Fixed
{
private:
    int _rawBi;
    static const int _bitShift = 8;
public:
    Fixed();
    Fixed(const Fixed &t);
    Fixed(const int &t);
    Fixed(const float &t);
    void setRawBits(int const raw);
    int getRawBits(void);
    Fixed &operator=(const Fixed &other);
    int toInt() const;
    float toFloat() const;
    ~Fixed();
    
};

std::ostream& operator<<( std::ostream& os, const Fixed& fixed );


