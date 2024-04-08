#include <iostream>
#include <string>
#include "iter.hpp"
#include <cstdlib>
#include <ctime>

void print(int const &i)
{
    std::cout << i << ", ";
}


int main(void)
{
    srand(time(NULL));

    FuncType  *arr = new FuncType[10];
    for (int i = 0; i < 10; i++)
        arr[i] = print;

    iter(arr, 10, print);
    return 0;
}