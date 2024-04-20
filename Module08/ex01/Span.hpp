#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <climits>

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
    void addNumber(int, int, size_t);

    int shortestSpan();
    int longestSpan();

    std::vector<int> getArr() const { return this->arr; };
};
std::ostream &operator<<(std::ostream &os, Span const &);
