#include "../include/Intern.hpp"

#include <iterator>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// https://stackoverflow.com/questions/5093090/whats-the-syntax-for-declaring-an-array-of-function-pointers-without-using-a-se
AForm *Intern::makeForm(const std::string &type, const std::string &name) {
    static std::string types[3] = {
        "shrubbery request",
        "robotomy request",
        "presidential request",
    };

    AForm* (* creators[3])(const std::string& name) = {
        ShrubberyCreationForm::create,
        RobotomyRequestForm::create,
        PresidentialPardonForm::create,
    };

    for (int i = 0; i < 3; i++) {
        if (type == types[i]) {
            AForm* created = creators[i](name);
            std::cout << "Intern created " << *created << std::endl;
            return created;
        }
    }
    throw InvalidFormType();
}

std::invalid_argument Intern::InvalidFormType() {
    return std::invalid_argument("invalid form type");
}
