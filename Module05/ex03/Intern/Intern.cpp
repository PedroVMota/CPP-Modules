#include "Intern.hpp"

Intern::Intern(){};
Intern::Intern(Intern const &o) { *this = o; }
Intern &Intern::operator=(Intern const &o)
{
    if (this == &o)
        return *this;
    return *this;
}

Intern::~Intern(){};


static AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

// Public Methods
AForm *Intern::makeForm(std::string const &formType, std::string const &formName)
{
	AForm *(*all_forms[])(const std::string target) = {
        &makePresident,
        &makeRobot,
        &makeShrubbery
    };

	std::string forms[] = {
        "Presidential Request",
        "Robotomy Request",
        "Shrubbery Request"
    };

	for (int i = 0; i < 3; i++)
		if (formType == forms[i])
		{
			std::cout << "Intern creates " << formName << " now" << std::endl;
			return (all_forms[i](formType));
		}
	std::cout << "Intern can not find the form: " << formName << std::endl;
	return (NULL);
}