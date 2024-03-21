#include "Intern/Intern.hpp"

int main(void)
{
  Bureaucrat *c = NULL;
  AForm *f = NULL;
  Intern *i = NULL;
  try
  {
    i = new Intern();
    c = new Bureaucrat("Andre Ventura", 140);

    f = i->makeForm("RobotomyRequestForm", "Natu");
    if (f)
    {
      f = i->makeForm("a", "Natu");
      c->signForm(*f);
      f->execute(*c);
    }
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "\n\n\n\n";
  if (c)
    delete c;
  if (i)
    delete i;
  if (f)
    delete f;
}
