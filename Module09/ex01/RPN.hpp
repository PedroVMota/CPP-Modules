#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <functional>


/* Using c++ 98 */

#ifndef COLORS
#define COLORS

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

#endif



typedef struct CustomStack{
  std::stack<std::string> stack;

  bool isOperator(std::string &ref)
  {
    return ref[0] == '+' || ref[0] == '-' || ref[0] == '*' || ref[0] == '/';
  }

  void push(std::string &ref)
  {

    std::stack<std::string> temp;
    std::istringstream iss(ref);
    std::string tempString = "";

    while(getline(iss, tempString, ' '))
    {
      if(tempString.size() > 0)
      {
        std::cout << MAGENTA << "Pushing: " << RESET << tempString << std::endl;
        ref.erase(0, tempString.size());
        stack.push(tempString);
      }
    }
  }


} CustomStack;

class RPN {
  private:
    CustomStack stack;

    bool isValidField(std::string &);
    bool tokenize(std::string &);
    bool calculate();

    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
  public:
    RPN(std::string &);
    ~RPN();
};