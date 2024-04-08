#include "Span.hpp"

Span::Span() {}
Span::Span(size_t n) : _maxN(n) {};

void Span::addNumber(int newN){
    if(this->arr.size() == this->_maxN)
    {
        throw std::runtime_error("The arr is full");
        return;
    }
    this->arr.push_back(newN);
}

int Span::shortestSpan() {
    if (this->arr.size() < 2) {
        throw std::runtime_error("Cannot find span: less than two numbers stored.");
    }

    std::sort(this->arr.begin(), this->arr.end());
    
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < this->arr.size(); ++i) {
        int span = this->arr[i] - this->arr[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }

    return minSpan;
}

int Span::longestSpan()
{
    if (this->arr.size() < 2) {
        throw std::runtime_error("Cannot find span: less than two numbers stored.");
    }

    std::sort(this->arr.begin(), this->arr.end());

    return this->arr.back() - this->arr.front();
}

Span::~Span() {}