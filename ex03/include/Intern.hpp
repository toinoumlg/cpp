#pragma once
#include "AForm.hpp"

class Intern {
public:
    static AForm *makeForm(const std::string &type, const std::string &name);
    static std::invalid_argument InvalidFormType();
};
