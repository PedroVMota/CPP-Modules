#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default") { grade = 150; }

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
