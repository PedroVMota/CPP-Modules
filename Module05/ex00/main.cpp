#include "Bureaucrat/Bureaucrat.hpp"
#include <iostream>

int main( void )
{
    try {
        Bureaucrat bureaucrat("ash", 2);

        std::cout << bureaucrat << std::endl;

        bureaucrat.incrementGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
        std::cout << bureaucrat << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
