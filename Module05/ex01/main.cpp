#include "Form/Form.hpp"
#include <exception>

int main(void) {
  try {
    Bureaucrat crata = Bureaucrat("Antonio", 30);
    std::cout << crata << std::endl;
    Form formula = Form("Formulario", 29, 30);
    std::cout << formula << std::endl;
    crata.signForm(formula);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
