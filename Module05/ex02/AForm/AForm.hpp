#pragma once
#include "../Bureaucrat/Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
private:
  const std::string name;
  bool isSigned;
  const int gradeToSign;
  const int gradeToExecute;

public:
  AForm();
  AForm(const AForm &);
  AForm(std::string name, int gradeToSign, int gradeToExecute);
  AForm &operator=(const AForm &);
  virtual ~AForm();

  // Exception
  class GradeTooHighException : public std::exception
  {
  public:
    const char *what() const throw() { return "Grade too high"; }
  };

  class GradeTooLowException : public std::exception
  {
  public:
    const char *what() const throw() { return "Grade too low"; }
  };
  virtual std::string getName() const;
  bool getSign() const;
  void setSign();
  int getGradeToSign() const;
  int getGradeToExecute() const;
  virtual void beSigned(Bureaucrat &other) = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &);
