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

void Bureaucrat::signForm(AForm &e) {
  try {
    e.beSigned(*this);
    std::cout << name << " assigned " << e.getName() << std::endl;
  } catch (const std::exception &) {
    std::cout << name << " couldn't assigned " << e.getName()
              << " because the grade is to low;" << std::endl;
  }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
  return out;
}
