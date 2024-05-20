#include "Span.hpp"

int main()
{
    Span sp = Span(4000);
    try{
        sp.addNumber(-2000, 2000, 5007);
        std::cout << sp << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}