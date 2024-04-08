#pragma once

#include <iostream>
#include <string>
#include <iterator>


typedef void (*FuncType)(int const &);

template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T a, T b) {
    return a < b ? a : b;
}

template <typename T>
T max(T a, T b) {
    return a > b ? a : b;
}


template <typename T>
void iter(T *array, size_t length, void (*f)(T const &)) {
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}