#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &name) : AForm(
    name, 25, 5) {
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (!getSigned())
        throw FormNeedSign();
    if (executor.getGrade() < getReqExec())
        throw GradeTooLowException();

    std::cout << executor << " has been pardoned by Zaphod Beeblebrox" <<
            std::endl;
}
