#include "Array.hpp"

// testing the class

int main()
{

    Array<int> a(100);

    for (size_t i = 0; i < a.size(); i++)
    {
        a[i] = i;
    }

    for (size_t i = 0; i < a.size(); i++)
    {
        std::cout << "a[" << i << "]: " << a[i] << ", ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    Array<int> b(100);

    b = a;

    try{
        for (size_t i = 0; i < 20; i++)
            std::cout << "b[" << i << "]: " << b[i] << ", ";
    }
    catch (std::out_of_range &e){
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
}