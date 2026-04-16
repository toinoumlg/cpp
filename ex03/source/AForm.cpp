#include "AForm.hpp"

#include <cmath>

#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(false), _req_sign(0), _req_exec(0) {
}

AForm::AForm(const std::string &name, const int sign,
             const int exec) : _name(name), _signed(false), _req_sign(sign),
                               _req_exec(exec) {
    if (_req_sign < 1 || _req_exec < 1)
        throw GradeTooHighException();
    if (_req_sign > 150 || _req_exec > 150)
        throw GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _req_sign)
        throw GradeTooLowException();
    _signed = true;
}

bool AForm::getSigned() const {
    return _signed;
}

std::string AForm::getName() const {
    return _name;
}

int AForm::getReqSign() const {
    return _req_sign;
}

int AForm::getReqExec() const {
    return _req_exec;
}

std::out_of_range AForm::GradeTooHighException() const {
    return std::out_of_range(_name + ", form grade is too high");
}

std::out_of_range AForm::GradeTooLowException() const {
    return std::out_of_range(_name + ", form grade is too low");
}

std::logic_error AForm::FormNeedSign() {
    return std::logic_error("form need to be signed before execution");
}

AForm::~AForm() {
}

std::ostream &operator<<(std::ostream &output, AForm const &form) {
    output << form.getName() << "{" << form.getReqSign() << ";" << form.
            getReqExec() << "}";
    return output;
}
