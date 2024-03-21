#include "Intern/Intern.hpp"

int main(void)
{
  Intern intern;
  AForm *paperwork;

  try
  {
    Bureaucrat b("Bureaucrat", 1);
    for (int i = 0; i < 4; i++)
    {
      switch (i)
      {
      case 0:
        paperwork = intern.makeForm("Presidential Request", "Shrub");
        break;
      case 1:
        paperwork = intern.makeForm("Robotomy Request", "Robot");
        break;
      case 2:
        paperwork = intern.makeForm("Shrubbery Request", "Pres");
        break;
      default:
        paperwork = intern.makeForm("HumanRights", "no");
      }

      if (paperwork)
      {
        b.signForm(*paperwork);
        b.executeForm(*paperwork);
        delete paperwork;
        std::cout << "\n";
      }
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}