#pragma once
#include "../ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "../RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "../PresidentialPardonForm/PresidentialPardonForm.hpp"

class Intern{
    public:
        Intern();
        Intern(Intern const &o);
        Intern &operator=(Intern const &o);
        ~Intern();
        AForm *makeForm(std::string const &formType, std::string const &formName);
};