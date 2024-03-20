#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 145, 137) {};
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other) {}
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
    if(this == &other)
        return *this;
    return *this;
}

void RobotomyRequestForm::beSigned(Bureaucrat &other) {
  if (other.getGrade() > this->getGradeToSign())
    throw AForm::GradeTooLowException();
  this->setSign();
}


RobotomyRequestForm::~RobotomyRequestForm() {}