#include "Span.hpp"

Span::Span() {}
Span::Span(size_t n) : _maxN(n){};

void Span::addNumber(int newN)
{
    if (this->arr.size() == this->_maxN)
    {
        throw std::runtime_error("The arr is full");
        return;
    }
    this->arr.push_back(newN);
}

int Span::shortestSpan()
{

    if (this->arr.size() < 2)
    {
        throw std::runtime_error("Cannot find span: less than two numbers stored.");
    }

    std::sort(this->arr.begin(), this->arr.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < this->arr.size(); ++i)
    {
        int span = this->arr[i] - this->arr[i - 1];
        if (span < minSpan)
        {
            minSpan = span;
        }
    }

    return minSpan;
}

int Span::longestSpan()
{
    if (this->arr.size() < 2)
        throw std::runtime_error("Cannot find span: less than two numbers stored.");
    std::sort(this->arr.begin(), this->arr.end());
    return this->arr.back() - this->arr.front();
}

void Span::addNumber(int min, int max, size_t lenght)
{
    srand(time(0));
    if (lenght > this->_maxN)
    {
        throw std::runtime_error("The amout of number is greater then the allowed size");
    }
    for (size_t i = 0; i < lenght; i++)
    {
        if (this->arr.size() >= this->_maxN)
        {
            throw std::runtime_error("The arr is full... Stopping the Optmized Add Number()\n");
        }
        try
        {
            this->arr.push_back(min + rand() % (max - min + 1));
        }
        catch (std::exception &e)
        {
            throw std::runtime_error(e.what());
        }
    }
}

Span::~Span() {}

std::ostream &operator<<(std::ostream &os, Span const &ref)
{
    std::vector<int> arr = ref.getArr();

    for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
    {
        if(it == arr.begin())
            os << "[" << *it << ", ";
        else if (it == arr.end() - 1)
            os << *it << "]";
        else
            os << *it << ", ";
        
    }
    return os;
}
