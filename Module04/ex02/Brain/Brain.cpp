#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
}

Brain::Brain(const Brain &other)
{
  for(int i = 0; i < 100; i++)
  {
    this->ideas[i] = other.ideas[i];
  }
}

Brain::~Brain()
{
}

Brain &Brain::operator=(const Brain &other)
{
  for (int i = 0; i < 100; i++)
  {
    this->ideas[i] = other.ideas[i];
  }
  return *this;
}

void Brain::setIdea(int index, std::string idea)
{
  if (index < 0 || index >= 100)
  {
    std::cout << "Index out of range" << std::endl;
    return;
  };
  this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
  if (index < 0 || index >= 100)
  {
    std::cout << "Index out of range" << std::endl;
    return "";
  };
  return this->ideas[index];
}
