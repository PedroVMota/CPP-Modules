#pragma once
#include "../AForm/AForm.hpp"

class AForm;

class ShrubberyCreationForm: public AForm {
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const &other);
        ShrubberyCreationForm(std::string const &newName);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
        virtual ~ShrubberyCreationForm();
        virtual void beSigned(Bureaucrat &other);
        virtual void execute(Bureaucrat const & executor) const;
};