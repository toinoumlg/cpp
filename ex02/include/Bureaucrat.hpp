#pragma once

#include <string>
#include <iostream>

class AForm;

class Bureaucrat {
public:
    Bureaucrat(const std::string &name, int grade);

    ~Bureaucrat();

    // Operator overloads
    Bureaucrat &operator+=(int i);

    Bureaucrat operator++(int);

    Bureaucrat &operator++();

    Bureaucrat &operator-=(int i);

    Bureaucrat operator--(int);

    Bureaucrat &operator--();


    // Modifier
    void incrementGrade();

    void incrementGrade(int amount);

    void decrementGrade();

    void decrementGrade(int amount);

    // Form stuff

    void signForm(AForm &form) const;

    void executeForm(const AForm &form) const;

    // Getters
    std::string getName() const;

    int getGrade() const;

    // Errors
    std::out_of_range GradeTooHighException() const;

    std::out_of_range GradeTooLowException() const;


private:
    const std::string &_name;
    int _grade;
};

std::ostream &operator<<(std::ostream &output, Bureaucrat const &bureaucrat);

