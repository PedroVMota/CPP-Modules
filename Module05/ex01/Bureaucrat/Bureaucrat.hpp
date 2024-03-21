#pragma once
#include "../Form/Form.hpp"
#include <string>

class Form;

class Bureaucrat {
private:
  const std::string name;
  int grade;

public:
  Bureaucrat();
  Bureaucrat(std::string name);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  Bureaucrat(std::string name, int number);
  ~Bureaucrat();
  void incrementGrade();
  void decrementGrade();
  const std::string &getName() const;
  int getGrade() const;

  void signForm(Form &e);

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw() { return "Grade too high"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw() { return "Grade too low"; }
  };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &o);
