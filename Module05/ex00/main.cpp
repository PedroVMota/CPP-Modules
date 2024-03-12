#include "Bureaucrat/Bureaucrat.hpp"
#include <iostream>

int main(void) {
  try {
    Bureaucrat burucrat3("Chess", 161);
    Bureaucrat burucrata2("Chess", 0);

  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
