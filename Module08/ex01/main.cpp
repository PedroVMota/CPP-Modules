#include "Span.hpp"

int main()
{
    Span sp = Span(100);
    sp.addNumber(-2000, 2000, 10);
    std::cout << sp << std::endl;
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    return 0;
}