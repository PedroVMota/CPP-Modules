#include "Form.hpp"

Form::Form()
    : name("Default"), isSigned(false), gradeToSign(75), gradeToExecute(30) {}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form &Form::operator=(const Form &other) {
  if (*this != other)
    return *this;
  this->name = other.name;
  this->isSigned = other.isSigned;
  this->gradeToSign = other.gradeToSign;
}
