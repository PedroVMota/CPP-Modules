#pragma once
#include "../AForm/AForm.hpp"

class AForm;

class PresidentialPardonForm: public AForm {
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const &other);
        PresidentialPardonForm(std::string const &newName);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
        virtual ~PresidentialPardonForm();
        virtual void beSigned(Bureaucrat &other);
        virtual void execute(Bureaucrat const & executor) const;
};