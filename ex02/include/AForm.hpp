#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
public:
    virtual ~AForm();

    void beSigned(const Bureaucrat &bureaucrat);

    virtual void execute(const Bureaucrat &executor) const = 0;

    // Getters
    bool getSigned() const;

    std::string getName() const;

    int getReqSign() const;

    int getReqExec() const;

    // Error
    std::out_of_range GradeTooLowException() const;

    std::out_of_range GradeTooHighException() const;

    static std::logic_error FormNeedSign();

protected:
    AForm();
    AForm(const std::string &name, int sign, int exec);

private:
    const std::string _name;
    bool _signed;
    const int _req_sign;
    const int _req_exec;
};

std::ostream &operator<<(std::ostream &output, AForm const &form);
