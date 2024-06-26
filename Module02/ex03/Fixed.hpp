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
    int getRawBits(void) const;
    Fixed &operator=(const Fixed &other);
    int toInt() const;
    float toFloat() const;
    ~Fixed();

    Fixed operator+(const Fixed &other);
    Fixed operator-(const Fixed &other);
    Fixed operator*(const Fixed &other);
    Fixed operator/(const Fixed &other);

    bool operator>(const Fixed &other);
    bool operator<(const Fixed &other);
    bool operator>=(const Fixed &other);
    bool operator<=(const Fixed &other);
    bool operator==(const Fixed &other);
    bool operator!=(const Fixed &other);

    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

};

std::ostream& operator<<( std::ostream& os, const Fixed& fixed );


