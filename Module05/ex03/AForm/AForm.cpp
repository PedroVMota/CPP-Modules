#include "AForm.hpp"

AForm::AForm()
    : name("Default"), isSigned(false), gradeToSign(75), gradeToExecute(30) {}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign),
      gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw AForm::GradeTooHighException();
  } else if (gradeToSign > 150 || gradeToExecute > 150) {
    throw AForm::GradeTooLowException();
  }
}
AForm &AForm::operator=(const AForm &other) {
  if (this != &other)
    return *this;
  this->isSigned = other.isSigned;
  return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return this->name; }

bool AForm::getSign() const { return this->isSigned; }

int AForm::getGradeToSign() const { return this->gradeToSign; }

int AForm::getGradeToExecute() const { return this->gradeToExecute; }

std::ostream &operator<<(std::ostream &out, const AForm &f) {
  out << f.getName() << " | " << f.getSign() << " | " << f.getGradeToSign()
      << " | " << f.getGradeToExecute();
  return out;
}

void AForm::setSign() {
  this->isSigned = true;
}
