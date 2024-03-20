#include "../AForm/AForm.hpp"

class AForm;

class RobotomyRequestForm: public AForm {
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const &other);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
        virtual ~RobotomyRequestForm();
        virtual void beSigned(Bureaucrat &other);
};