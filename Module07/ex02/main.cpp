#include <iostream>
#include <Array.hpp>
#include <time.h>
#include <stdlib.h>


#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE                                                                     
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
}