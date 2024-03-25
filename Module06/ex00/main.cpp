#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if(ac == 1)
    {
        std::cout << "Insert an argument! ./Scallar <Char | Integer | Float | Double >\n\n";
        return 1;
    }
    ScalarConverter::convert((av[1]));
    return 0;
}