#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>
#include <iostream>
#include <string>
#include <cstdlib>

Base *generate(void);
void identify_from_pointer(Base *p);
void identify_from_reference(Base &p);

int main(void)
{
    Base *c;

    std::cout << "TEST 1" << std::endl;
    c = generate();

    std::cout << std::endl;
    identify_from_pointer(c);
    std::cout << std::endl;
    identify_from_reference(*c);
        

    delete c;
    return EXIT_SUCCESS;
}