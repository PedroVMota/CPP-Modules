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
      if (isalpha(ref[i])) // Check if the character is alphabetic
        return false;
      if (ref[i] == ' ' || ref[i] == '\t')
        return true;
    }
    return true; // Return true if all characters are valid
  }
  return false; // Return false if the string does not match any valid pattern
}

bool RPN::tokenize(std::string &ref)
{
  std::istringstream iss(ref);
  std::string token;
  while (getline(iss, token, ' '))
  {
    bool validation = this->isValidField(token);
    if (!validation)
      return false;
    if (validation)
      stack.push(token);
  }

  std::list<std::string> temp = stack.stack;
  int operatorCount = 0;
  int operandCount = 0;
  while (!temp.empty())
  {
    if (stack.isOperator(temp.front()))
      operatorCount++;
    else
    {
      std::string operand = temp.front();
      if (operand.size() > 1)
        return false;
      operandCount++;
    }
    temp.pop_front();
  }
  if (operatorCount != operandCount - 1)
    return false;
  return true;
}

bool RPN::calculate()
{
  std::list<std::string> temp = stack.stack;
  std::list<double> result;
  std::list<std::string>::iterator it = temp.begin();
  while (it != temp.end())
  {
    std::string token = *it;
    if (stack.isOperator(token))
    {
      if (result.size() < 2)
      {
        std::cout << RED << "Error: " << RESET << "Not enough operands" << std::endl;
        return false;
      }
      double b = result.back();
      result.pop_back();
      double a = result.back();
      result.pop_back();
      double res;
      if (token == "+")
        res = a + b;
      else if (token == "-")
        res = a - b;
      else if (token == "*")
        res = a * b;
      else if (token == "/")
      {
        if (b == 0)
        {
          std::cout << RED << "Error: " << RESET << "Division by zero" << std::endl;
          return false;
        }
        res = a / b;
      }
      result.push_back(res);
    }
    else
    {
      try
      {
        double num = this->stringToDouble(token);
        result.push_back(num);
      }
      catch (const std::invalid_argument &)
      {
        std::cout << RED << "Error: " << RESET << "Invalid number" << std::endl;
        return false;
      }
    }
    it++;
  }

  if (result.size() == 1)
  {
    std::cout << "Result: " << result.back() << std::endl;
    return true;
  }
  return false;
}

RPN::RPN(std::string &ref) : stack()
{
  if (!tokenize(ref))
  {
    std::cout << RED << "Error: " << RESET << "Invalid expression" << std::endl;
    return;
  }
  std::list<std::string> inverse;
  while (!stack.stack.empty())
  {
    inverse.push_front(stack.stack.front());
    stack.stack.pop_front();
  }
  stack.stack = inverse;
  calculate();
}

RPN::~RPN()
{
  std::cout << YELLOW << "Destructor" << RESET << std::endl;
}