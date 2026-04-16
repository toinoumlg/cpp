#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
public:
    ShrubberyCreationForm(const std::string& name);

    static AForm* create(const std::string &name);

    void execute(const Bureaucrat &executor) const;

    static std::invalid_argument FileAlreadyExists();
};