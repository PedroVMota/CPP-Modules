#pragma once
#include "../Bureaucrat/Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;

class Form {
public:
  Form();
  Form(const Form &);
  Form(std::string name, int gradeToSign, int gradeToExecute);
  Form &operator=(const Form &);
  ~Form();

  // Exception
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw() { return "Grade too high"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw() { return "Grade too low"; }
  };
  std::string getName() const;
  bool getSign() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  void beSigned(const Bureaucrat &other);

private:
  const std::string name;
  bool isSigned;
  const int gradeToSign;
  const int gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, const Form &);
