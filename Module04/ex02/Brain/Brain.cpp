#include <Brain.hpp>

Brain::Brain(){
    std::cout << "Default Brain Constructor" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Copy Brain Constructor" << std::endl;
    *this = other;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain Assignation Operator" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    return *this;
}

void Brain::setIdea(int index, std::string idea)
{
    if(index < 0 || index >= 100)
    {
        std::cout << "Index out of range" << std::endl;
        return;
    };
    this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    if(index < 0 || index >= 100)
    {
        std::cout << "Index out of range" << std::endl;
        return "";
    };
    return this->ideas[index];
}