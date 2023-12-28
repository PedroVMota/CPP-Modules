#include <string>
#include <iostream>

class Fixed
{
private:
    int _integer;
    static const int _const_integer = 8;
public:
    Fixed();
    Fixed(const Fixed &t);
    Fixed &operator=(const Fixed &other);
    int getRawBits( void );
    void setRawBits( int const raw );
    ~Fixed();
};


