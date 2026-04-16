#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
public:
    Form(const std::string &name, int sign, int exec);

    ~Form();

    void beSigned(const Bureaucrat &bureaucrat);

    // Getters

    bool getSigned() const;

    std::string getName() const;

    int getReqSign() const;

    int getReqExec() const;


    // Error
    std::out_of_range GradeTooLowException() const;

    std::out_of_range GradeTooHighException() const;

private:
    const std::string _name;
    bool _signed;
    const int _req_sign;
    const int _req_exec;
};

std::ostream &operator<<(std::ostream &output, Form const &form);
