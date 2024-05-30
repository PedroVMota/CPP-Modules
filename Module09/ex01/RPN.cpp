#include "RPN.hpp"
bool RPN::isValidField(std::string &ref)
{
  while (ref[0] == ' ')
    ref.erase(0, 1);
  if (ref == "+" || ref == "-" || ref == "*" || ref == "/")
    return true;
  if (ref[0] >= '0' && ref[0] <= '9')
  {
    bool isFloat = 0;
    for (size_t i = 1; i < ref.size(); i++)
    {
      if (!isFloat && ref[i] == '.')
        isFloat = 1;
      else if (isFloat && ref[i] == '.')
        return false;
      if ((ref[i] < '0' || ref[i] > '9') && (ref[i] != ' ' && ref[i] != '\t'))
        return false;
      if(ref[i] == ' ' || ref[i] == '\t')
        return true;
    }
  }
  return true;
}

bool RPN::tokenize(std::string &ref)
{
  std::istringstream iss(ref);
  std::string token;
  while (getline(iss, token, ' '))
  {
    std::cout << YELLOW << "Update: " << token << RESET << std::endl;
    bool validation = this->isValidField(token);
    if (!validation)
    {
      std::cout << RED << "Error: " << RESET << "Invalid field: " << token << std::endl;
      return false;
    }
    if (validation)
    {
      std::cout << GREEN << "Ok: " << RESET << "Success" << std::endl;
      stack.push(token);
    }
  }

  std::cout << MAGENTA << "Stack size: " << stack.stack.size() << RESET << std::endl;
  while (!stack.stack.empty())
  {
    std::cout << "Index: " << stack.stack.size() - 1 << " Value: " << stack.stack.top() << std::endl;
    stack.stack.pop();
  }
  return true;
}

RPN::RPN(std::string &ref) : stack()
{
  std::cout << YELLOW << "Analizing: " << RESET << ref << std::endl;
  if (!tokenize(ref))
  {
    std::cout << RED << "Error: " << RESET << "Invalid expression" << std::endl;
  }
}

RPN::~RPN()
{
  std::cout << YELLOW << "Destructor" << RESET << std::endl;
}