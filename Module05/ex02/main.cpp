#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "PresidentialPardonForm/PresidentialPardonForm.hpp"

int main(void) {
  AForm *shrubbery = NULL;
  AForm *Robotomy = NULL;
  AForm *Presidential = NULL;
  Bureaucrat *crata = NULL;
  try {
    crata = new Bureaucrat("Antonio", 6);

    shrubbery = new ShrubberyCreationForm("Natureza");
    std::cout << *crata << std::endl << *shrubbery << std::endl;
    crata->signForm(*shrubbery);
    shrubbery->execute(*crata);
    
    std::cout << "\n";

    Robotomy = new RobotomyRequestForm("Robotica");
    std::cout << *crata << std::endl << *Robotomy << std::endl;
    crata->signForm(*Robotomy);
    Robotomy->execute(*crata);

    std::cout << "\n";

    Presidential = new PresidentialPardonForm("Presidential");
    std::cout << *crata << std::endl << *Presidential << std::endl;
    crata->signForm(*Presidential);
    Presidential->execute(*crata);

  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  delete shrubbery;
  delete crata;
  delete Presidential;
  delete Robotomy;
}
