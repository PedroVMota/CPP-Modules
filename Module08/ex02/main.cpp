#include <iostream>
#include <pthread.h>
#include "MutantStack.hpp"
#include <ctime>
#include <cstdlib>

const int NUM_ELEMENTS = 20;

template <class Type>
void push_elements(MutantStack<Type> &arr)
{
    for (int i = 0; i < NUM_ELEMENTS; ++i)
        arr.push(rand() % 12001 - 1000);
}

int main()
{
    srand(0);
    for (int loopMain = 0; loopMain < 10; loopMain++)
    {
        MutantStack<int> origin;
        push_elements(origin);
        MutantStack<int> clone(origin);

        // Test iterator
        for (MutantStack<int>::iterator iO = origin.begin(), iC = clone.begin(); iO != origin.end() && iC != clone.end(); ++iO, ++iC)
        {
            if (*iO != *iC)
            {
                std::cout << "Iterator Error: " << *iO << ":" << *iC << std::endl;
                break;
            }
        }

        // Test const_iterator
        for (MutantStack<int>::const_iterator iO = origin.cbegin(), iC = clone.cbegin(); iO != origin.cend() && iC != clone.cend(); ++iO, ++iC)
        {
            if (*iO != *iC)
            {
                std::cout << "Const Iterator Error: " << *iO << ":" << *iC << std::endl;
                break;
            }
        }

        // Test reverse_iterator
        for (MutantStack<int>::reverse_iterator iO = origin.rbegin(), iC = clone.rbegin(); iO != origin.rend() && iC != clone.rend(); ++iO, ++iC)
        {
            if (*iO != *iC)
            {
                std::cout << "Reverse Iterator Error: " << *iO << ":" << *iC << std::endl;
                break;
            }
        }

        // Test const_reverse_iterator
        for (MutantStack<int>::const_reverse_iterator iO = origin.crbegin(), iC = clone.crbegin(); iO != origin.crend() && iC != clone.crend(); ++iO, ++iC)
        {
            if (*iO != *iC)
            {
                std::cout << "Const Reverse Iterator Error: " << *iO << ":" << *iC << std::endl;
                break;
            }
        }
        std::cout << "Everything is correct \n";
    }
}