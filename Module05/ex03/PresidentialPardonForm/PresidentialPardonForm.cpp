#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &newName) : AForm(newName, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5){};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other)
{
}
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
  if(this == &other)
    return *this;
  return *this;
}

void PresidentialPardonForm::beSigned(Bureaucrat &other)
{
  if (other.getGrade() > this->getGradeToSign())
    throw AForm::GradeTooLowException();
  this->setSign();
}


void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
  if(!this->getSign())
    throw AForm::FormNotSigned();
  if (this->getGradeToExecute() < executor.getGrade())
    throw AForm::GradeTooLowException();
  std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
  std::cout << executor.getName() << ": executed " << this->getName() << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm() {}