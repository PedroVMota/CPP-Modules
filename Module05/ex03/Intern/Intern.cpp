#include "Intern.hpp"

Intern::Intern(){};
Intern::Intern(Intern const &o) { *this = o; }
Intern &Intern::operator=(Intern const &o)
{
    if (this == &o)
        return *this;
    return *this;
}

Intern::~Intern(){};
AForm *Intern::makeForm(std::string const &formType, std::string const &formName)
{
    if (!(formType == "RobotomyRequestForm" || formType == "PresidentialPardonForm" || formType == "ShrubberyCreationForm"))
    {
        std::cerr << "The intern couldn't find the form: " << formName << std::endl;
        return NULL;
    }
    std::cout << "Intern creates " << formType  << std::endl;
    if (formType == "RobotomyRequestForm")
        return new RobotomyRequestForm(formName);
    else if (formType == "PresidentialPardonForm")
        return new PresidentialPardonForm(formName);
    else if (formType == "ShrubberyCreationForm")
        return new ShrubberyCreationForm(formName);
    return NULL;
}