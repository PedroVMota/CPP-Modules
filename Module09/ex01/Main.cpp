#include <RPN.hpp>
#include <ctime>
#include <cstdlib>

int main(int ac, char **av)
{
  if(ac == 1)
  {
    std::cout << "Usage: ./rpn \"expression\"" << std::endl;
    return 1;
  }
  std::string argument = av[1];
  RPN rpn(argument);
  return 0;
}