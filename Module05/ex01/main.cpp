#include "Form/Form.hpp"
#include <exception>

int main(void) {
  try {
    Bureaucrat crata = Bureaucrat("Antonio", 30);
    std::cout << crata << std::endl;
    Form formula = Form("Formulario", 20, 29);
    std::cout << formula << std::endl;
    crata.signForm(formula);
    formula.beSigned(crata);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
