#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string const &newName) : AForm(newName, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45){};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
  if(this == &other)
    return *this;
  return *this;
}

void RobotomyRequestForm::beSigned(Bureaucrat &other)
{
  if (other.getGrade() > this->getGradeToSign())
    throw AForm::GradeTooLowException();
  this->setSign();
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
  if(!this->getSign())
    throw AForm::FormNotSigned();
  if (this->getGradeToExecute() < executor.getGrade())
    throw AForm::GradeTooLowException();
  std::cout << "* Drill Noises *" << std::endl;
  std::srand(std::time(NULL));
  int randomValue = std::rand() % 2;
  if(randomValue == 1)
    std::cout << executor.getName() << " has been robotomized" << std::endl;
  if(randomValue == 0)
    std::cout << executor.getName() << "was not robotomized" << std::endl;
  std::cout << executor.getName() << ": executed " << this->getName() << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm() {}