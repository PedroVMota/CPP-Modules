#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name("default") { grade = 150; }

Bureaucrat::Bureaucrat(std::string name) : name(name), grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name) {
  if (other.grade < 1)
    throw Bureaucrat::GradeTooHighException();
  if (other.grade > 150)
    throw Bureaucrat::GradeTooLowException();
  grade = other.grade;
}

Bureaucrat::Bureaucrat(std::string name, int number) : name(name) {
  if (number < 1)
    throw Bureaucrat::GradeTooHighException();
  if (number > 150)
    throw Bureaucrat::GradeTooLowException();
  this->grade = number;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this == &other)
    return *this;
  grade = other.grade;
  return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::incrementGrade() {
  if (grade == 1)
    throw Bureaucrat::GradeTooHighException();
  grade--;
}

void Bureaucrat::decrementGrade() {
  if (grade == 150)
    throw Bureaucrat::GradeTooLowException();
  grade++;
}

void Bureaucrat::signForm(const Form &e)
{
  if (e.getGradeToSign() >= this->grade)
    std::cout << this->name << " signs " << e.getName() << std::endl;
  else
    std::cout << this->name << " cannot sign " << e.getName() << " because his grade is too low" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return out;
}
