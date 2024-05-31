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
    bool validation = this->isValidField(token);
    if (!validation)
      return false;
    if (validation)
      stack.push(token);
  }

  std::stack <std::string> temp = stack.stack;
  int operatorCount = 0;
  int operandCount = 0;
  while (!temp.empty())
  {
    if (stack.isOperator(temp.top()))
      operatorCount++;
    else
      operandCount++;
    temp.pop();
  }
  if (operatorCount != operandCount - 1)
    return false;
  return true;
}

// Calculate the result of the RPN expression
bool RPN::calculate() {
    std::stack<std::string> temp = stack.stack;
    std::stack<double> result;

    while (!temp.empty()) {
        std::string token = temp.top();
        temp.pop();
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (result.size() < 2) {
                std::cout << RED << "Error: " << RESET << "Not enough operands" << std::endl;
                return false;
            }
            double b = result.top();
            result.pop();
            double a = result.top();
            result.pop();
            double res;
            if (token == "+") res = a + b;
            else if (token == "-") res = a - b;
            else if (token == "*") res = a * b;
            else if (token == "/") {
                if (b == 0) {
                    std::cout << RED << "Error: " << RESET << "Division by zero" << std::endl;
                    return false;
                }
                res = a / b;
            }
            result.push(res);
        } else {
            try {
                double num = std::stod(token);
                result.push(num);
            } catch (const std::invalid_argument&) {
                std::cout << RED << "Error: " << RESET << "Invalid number" << std::endl;
                return false;
            }
        }
    }

    if (result.size() == 1) {
        std::cout << "Result: " << result.top() << std::endl;
        return true;
    }
    return false;
}

RPN::RPN(std::string &ref) : stack()
{
  std::cout << YELLOW << "Analizing: " << RESET << ref << std::endl;
  if (!tokenize(ref))
  {
    std::cout << RED << "Error: " << RESET << "Invalid expression" << std::endl;
    return;
  }
  std::cout << GREEN << "Success: " << RESET << "Expression is valid" << std::endl;
  // inverse stack
  std::stack<std::string> inverse;
  while (!stack.stack.empty())
  {
    inverse.push(stack.stack.top());
    stack.stack.pop();
  }
  stack.stack = inverse;
  calculate();
}

RPN::~RPN()
{
  std::cout << YELLOW << "Destructor" << RESET << std::endl;
}