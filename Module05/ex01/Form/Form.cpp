#include "Form.hpp"

Form::Form()
    : name("Default"), isSigned(false), gradeToSign(75), gradeToExecute(30) {}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign),
      gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw Form::GradeTooHighException();
  } else if (gradeToSign > 150 || gradeToExecute > 150) {
    throw Form::GradeTooLowException();
  }
}
Form &Form::operator=(const Form &other) {
  if (this != &other)
    return *this;
  this->isSigned = other.isSigned;
  return *this;
}

Form::~Form() {}

std::string Form::getName() const { return this->name; }

bool Form::getSign() const { return this->isSigned; }

int Form::getGradeToSign() const { return this->gradeToSign; }

int Form::getGradeToExecute() const { return this->gradeToExecute; }

void Form::beSigned(const Bureaucrat &other) {
  if (other.getGrade() > this->gradeToSign) {
    throw Form::GradeTooLowException();
  }
  this->isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
  out << f.getName() << " | " << f.getSign() << " | " << f.getGradeToSign()
      << " | " << f.getGradeToExecute();
  return out;
}
