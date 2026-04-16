#pragma once
#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
public:
    PresidentialPardonForm(const std::string& name);
    void execute(const Bureaucrat &executor) const;
};
