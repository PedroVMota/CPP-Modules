#include <iostream>
#include <string>

class Form {
public:
  Form();
  Form(const Form &);
  Form &operator=(const Form &);
  ~Form();

  // Exception
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw() { return "Grade too hight"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw() { return "Grade too low"; }
  };

private:
  const std::string name;
  bool isSigned;
  const int gradeToSign;
  const int gradeToExecute;
};
