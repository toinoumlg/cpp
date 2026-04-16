#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, const int sign,
           const int exec) : _name(name), _signed(false), _req_sign(sign),
                             _req_exec(exec) {
    if (_req_sign < 1 || _req_exec < 1)
        throw GradeTooHighException();
    if (_req_sign > 150 || _req_exec > 150)
        throw GradeTooLowException();
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= _req_sign)
        _signed = true;
    else
        throw GradeTooLowException();
}

bool Form::getSigned() const {
    return _signed;
}

std::string Form::getName() const {
    return _name;
}

int Form::getReqSign() const {
    return _req_sign;
}

int Form::getReqExec() const {
    return _req_exec;
}

std::out_of_range Form::GradeTooHighException() const {
    return std::out_of_range(_name + ", form grade is too high");
}

std::out_of_range Form::GradeTooLowException() const {
    return std::out_of_range(_name + ", form grade is too low");
}

Form::~Form() {
}

std::ostream &operator<<(std::ostream &output, Form const &form) {
    output << form.getName() << "{" << form.getReqSign() << ";" << form.
            getReqExec() << "}";
    return output;
}
