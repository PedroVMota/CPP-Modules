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
    int  *arr = new int[10];
    for (int i = 0; i < 10; i++)
        arr[i] = 42;
    iter(arr, 10, print);
    delete[] arr;
    return 0;
}