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

  class FormNotSigned : public std::exception
  {
  public:
    const char *what() const throw() { return "Form is not assigned\n"; }
  };

  virtual std::string getName() const;
  bool getSign() const;
  void setSign();
  int getGradeToSign() const;
  int getGradeToExecute() const;
  virtual void beSigned(Bureaucrat &other) = 0;
  virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &);
