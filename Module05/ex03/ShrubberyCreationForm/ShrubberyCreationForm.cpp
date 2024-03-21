#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &newName) : AForm(newName, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137){};

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
  if(this == &other)
    return *this;
  return *this;
}

void ShrubberyCreationForm::beSigned(Bureaucrat &other)
{
  if (other.getGrade() > this->getGradeToSign())
    throw AForm::GradeTooLowException();
  this->setSign();
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
  if(!this->getSign())
    throw AForm::FormNotSigned();
  if (this->getGradeToExecute() < executor.getGrade())
    throw AForm::GradeTooLowException();

  std::string filename = this->getName() + "_shrubbery";
  std::ofstream file(filename.c_str());
  if (!file.is_open())
  {
    std::cerr << "Error: Creating file\n";
    return;
  }

  file << "  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⢀⣀⡀⠀⠀⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
  file << "⠀⢀⢀⠠⢄⠀⠀⠘⠀⠠⠼⡀⠠⠤⣀⣀⣾⣷⡾⣿⣷⣀⢳⣿⣿⣿⣦⣆⡠⢀⣀⡸⠄⢀⠘⠤⢄⠀⠤⢄⢀⠀⠀⠀⠡⠜⠀⠀⠀" << std::endl;
  file << "⠀⠀⠀⠀⠀⠀⠀⢠⠀⠀⢠⠀⠀⢠⣿⣏⠱⢾⡙⢏⠟⡥⢩⠛⣼⠷⢫⡹⡿⢟⢿⣛⡿⣿⣷⣦⣠⣤⡄⠀⠀⡄⠀⠀⡄⢠⠀⠀⠀" << std::endl;
  file << "⠀⠀⠰⠀⢰⠒⠁⠈⠒⣶⣬⣶⣟⠻⡹⢾⣿⠻⠍⠆⠈⠄⡀⢩⢆⠙⡀⠇⣉⢾⡾⣵⣾⣿⣯⢿⣟⣿⣿⣶⠐⠁⠐⠒⠁⠈⠀⠀⠀" << std::endl;
  file << "⠀⠀⢀⠀⢀⠀⢂⣰⣟⠏⡿⣿⣟⣳⣕⣻⣦⢋⡔⠀⠁⠠⠐⠈⡌⠀⢠⠐⣊⠲⣱⢻⡾⣽⣻⢿⣾⢟⣿⣿⣿⣤⣄⡀⠆⠸⠀⠀⠀" << std::endl;
  file << "⠀⠀⠈⠀⢰⣤⣶⣿⣯⣞⣽⣿⣛⢶⡺⣧⢆⣡⡀⠄⡁⠐⠤⢁⠢⢡⠄⣒⠦⢳⡡⣏⡖⢧⢫⢏⡜⣯⣿⣻⣽⢻⣿⣧⣄⣀⠀⠀⠀" << std::endl;
  file << "⠀⠠⢰⣶⠾⡟⡧⣿⢿⡿⣿⣽⣛⣶⣽⣯⣛⠤⣐⠈⡄⢩⠐⢂⡱⣠⢛⡴⢩⠳⣝⣭⢻⣭⡷⣎⣽⣽⣻⣷⢾⣩⣖⣿⡿⠋⠀⠀⠀" << std::endl;
  file << "⠀⠀⢀⣻⢮⡱⢻⣿⢯⣿⡙⡷⢻⡙⣾⣳⡿⣏⡙⣎⡐⡡⡜⢆⢧⡱⢎⠾⣥⢻⡼⣾⠻⡅⡛⡗⣿⢾⣻⣿⣟⣶⣿⣻⣷⡶⠀⠀⠀" << std::endl;
  file << "⠀⠨⢙⣿⣯⣷⡿⢇⠲⡅⠹⢈⠡⢏⡔⢫⣟⣾⣝⣦⣳⡱⣭⣞⢦⣝⢮⣻⡜⣧⣟⡹⠅⢀⠡⢙⠴⡻⢭⢓⡎⠗⣮⠿⣿⣦⡀⠀⠀" << std::endl;
  file << "⠀⢠⢭⡹⠬⣙⢳⡉⠂⢀⠐⠠⠑⡄⢬⢲⣹⣿⣿⣿⣷⣿⣷⣿⣷⣿⣿⣷⣹⣶⢏⡒⠀⠂⢀⠁⢊⠘⣇⠎⠘⡠⠃⡞⡥⠾⣧⡄⠀" << std::endl;
  file << "⢀⡸⡑⠆⠡⠐⢨⠚⠄⣀⠂⡅⢣⠼⣭⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣩⠀⢂⠀⠎⢠⠑⡈⠀⢂⠠⠑⠠⠜⡓⣎⣳⡦" << std::endl;
  file << "⡨⢒⠠⠀⡐⠈⡀⡘⠰⣠⢓⣬⢳⣿⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣡⡐⠆⡨⠘⡀⠆⢀⠐⠀⡂⢌⡡⢆⣹⠴⣻⠀" << std::endl;
  file << "⠁⣇⠒⡁⠄⡠⢡⢈⣅⠲⣭⢾⣿⣿⣿⣿⣿⣿⣿⣿⡯⠿⢿⣿⣿⡿⢿⣿⣿⣿⣿⣿⣽⣡⡗⣱⡜⡰⢂⠠⡑⡌⢀⡳⢍⣦⢻⣏⠁" << std::endl;
  file << "⠀⠗⣏⢄⢣⡔⣢⠝⣆⠷⣮⣷⣿⣿⣿⣿⣿⡿⠟⢿⣿⣶⣼⣿⡿⣧⣿⣿⠾⠛⢛⣿⣿⣿⣿⣿⣼⠱⣊⠶⡱⣍⢦⠹⣜⡸⢿⣅⠀" << std::endl;
  file << "⠀⢀⠙⠘⡯⣶⣿⣞⣿⣿⣾⣿⣿⣿⣿⣿⠛⣟⣆⠀⠙⣿⣿⣿⣿⣿⣿⠃⡆⠀⠀⣿⣿⣿⣿⣿⣷⣯⢧⣓⡳⡜⡶⣫⢼⣹⡧⠛⠁" << std::endl;
  file << "⠀⠀⠁⠀⠐⠿⠿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠿⣿⣿⣆⠀⢸⣿⣿⣿⣿⡿⠀⠀⣀⣼⣿⣿⣿⣿⣿⣿⣿⣧⣿⣵⣫⡵⠯⠾⠽⠃⠀⠀" << std::endl;
  file << "⠀⠈⠈⠀⠸⠤⡀⠻⠿⠛⢙⠟⠟⠁⠧⠔⠀⠠⠍⠛⢿⣿⣿⣿⣿⣿⣇⣴⣾⣿⠟⢋⠉⠻⢿⣿⣿⣿⣿⡿⠿⡀⠠⠤⡀⢀⠀⠀⠀" << std::endl;
  file << "⠀⢀⠠⠀⢠⠀⠀⠘⠀⠀⠘⠀⠀⠀⡄⢀⠀⠄⠠⠁⠂⠹⣿⣿⣿⣿⣿⣿⠛⠀⠀⠜⠀⠀⠈⠀⠈⢈⠀⢠⠀⠁⠠⠀⠀⠘⠀⠀⠀" << std::endl;
  file << "⠀⠈⠀⠒⠂⠈⠒⢲⠀⠐⠲⠁⠐⠒⠁⠀⠒⠀⠈⠒⠎⠈⣿⣿⣿⣿⡟⠁⠐⠒⠀⢱⠒⠀⠰⠒⠊⠀⠒⠊⠈⠒⠂⠀⠖⢲⠀⠀⠀" << std::endl;
  file << "⠀⠐⠀⢀⡰⠀⢀⣀⠀⢀⣀⠄⢀⣀⠆⠐⢀⠀⠐⣀⡀⠀⣿⣿⣿⣿⣻⠀⠆⣀⠀⢀⣀⠀⢀⣀⡀⠀⠀⡐⠀⢀⡀⠀⣀⣀⠀⠀⠀" << std::endl;
  file << "⠀⢀⢀⠤⢄⠀⠄⠘⠀⠀⠌⡀⠀⠠⡀⢀⠠⠀⢀⠤⠀⠀⣿⣿⣿⣿⣿⠀⡀⠀⠀⡸⠀⠀⠈⠤⠀⢀⠀⢄⢀⠂⠄⠀⠁⠜⠀⠀⠀" << std::endl;
  file << "⠀⠀⠀⠀⠀⠀⠄⢠⠀⠀⢠⠂⠀⠀⠃⠀⠀⠀⠀⠀⡄⠀⣿⣿⣿⣿⣿⡀⠃⠀⠀⢠⠀⠀⢠⠀⠄⠀⠀⠀⠀⡄⠀⠀⡄⢠⠀⠀⠀" << std::endl;
  file << "⠀⢐⠰⠁⢐⠒⠀⠀⠂⠀⠈⠂⠀⠈⡆⠰⠀⠒⠐⠁⢐⢒⣿⣿⣿⣿⣿⡇⡎⠀⠂⡊⠀⠀⠂⠀⠑⠐⠁⢰⠐⠁⠐⠂⠀⠈⠀⠀⠀" << std::endl;
  file << "⠀⠀⢀⠀⢀⢀⠀⠸⠀⠀⠸⠀⠀⠀⡀⠀⠀⡀⢀⠂⠆⣸⣿⣿⣿⣿⣿⡇⡀⠀⡀⠸⠀⠀⢈⠀⠁⢀⠀⢀⢀⠃⢀⠀⠅⠸⠀⠀⠀" << std::endl;
  file << "⠀⠈⠀⠀⠘⠀⠀⢀⠀⠀⢠⠂⠀⠀⠃⠈⠀⠀⠐⠀⠀⣾⣿⣿⣿⣿⣿⣿⣀⠀⠀⢡⠀⠀⢀⠀⡀⠈⠀⠈⠀⡀⠀⠀⡀⢠⠀⠀⠀" << std::endl;
  file << "⠀⠠⢀⠒⢢⠀⠐⠊⠀⠐⠊⠄⠐⠒⡄⣀⣂⣤⣤⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣬⣒⡀⠈⠒⠀⠀⠐⢢⠀⠑⠂⠀⠑⠈⠀⠀⠀" << std::endl;
  file << "⠀⠀⠀⠀⠀⠀⠀⠐⠀⠀⠐⠀⠀⠀⠁⠈⢀⠈⠉⡉⠍⠉⡏⠉⠉⠉⠉⠉⢉⠉⠀⢰⠁⠀⠰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠐⠀⠀⠀" << std::endl;

  file.close();

  std::cout << executor.getName() << ": executed " << this->getName() << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}