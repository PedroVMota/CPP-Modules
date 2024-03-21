#pragma once
#include "../AForm/AForm.hpp"

class AForm;

class RobotomyRequestForm: public AForm {
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const &other);
        RobotomyRequestForm(std::string const &newName);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
        virtual ~RobotomyRequestForm();
        virtual void beSigned(Bureaucrat &other);
        virtual void execute(Bureaucrat const & executor) const;
};