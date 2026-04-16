#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm(const std::string &name);

    static AForm* create(const std::string &name);

    void execute(const Bureaucrat &executor) const;

    static std::runtime_error AudioEngineError();

    static std::invalid_argument WrongAudioFile();
};
