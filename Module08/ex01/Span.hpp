#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span
{
private:
    size_t _maxN;
    std::vector<int> arr;
public:
    Span();
    Span(size_t);
    Span &operator=(Span const &);
    ~Span();

    void addNumber(int);

    int shortestSpan();
    int longestSpan();
};