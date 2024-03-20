#include "../AForm/AForm.hpp"

class AForm;

class ShrubberyCreationForm: public AForm {
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const &other);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
        virtual ~ShrubberyCreationForm();
        virtual void beSigned(Bureaucrat &other);
        void print() const;
};