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
  clock_t start = clock();
  std::string argument = av[1];
  RPN rpn(argument);
  clock_t end = clock();
  std::cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
  return 0;
}