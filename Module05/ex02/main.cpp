#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"

int main(void) {
  try {
    Bureaucrat crata = Bureaucrat("Antonio", 150);
    std::cout << crata << std::endl;


    ShrubberyCreationForm shrubbery = ShrubberyCreationForm();
    std::cout << shrubbery << std::endl;
    crata.signForm(shrubbery);
    

    RobotomyRequestForm robotic = RobotomyRequestForm();
    std::cout << robotic << std::endl;
    crata.signForm(robotic);

  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
