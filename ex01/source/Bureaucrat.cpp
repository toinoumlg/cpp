#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();

    _grade = grade;
}

Bureaucrat &Bureaucrat::operator+=(const int i) {
    incrementGrade(i);
    return *this;
}

Bureaucrat Bureaucrat::operator++(int) {
    Bureaucrat tmp(*this);
    incrementGrade();
    return tmp;
}

Bureaucrat &Bureaucrat::operator++() {
    incrementGrade();
    return *this;
}

Bureaucrat Bureaucrat::operator--(int) {
    Bureaucrat tmp(*this);
    decrementGrade();
    return tmp;
}

Bureaucrat &Bureaucrat::operator--() {
    decrementGrade();
    return *this;
}

Bureaucrat &Bureaucrat::operator-=(const int i) {
    decrementGrade(i);
    return *this;
}


void Bureaucrat::incrementGrade() {
    _grade--;
    if (_grade < 1) {
        throw GradeTooHighException();
    }
}

void Bureaucrat::incrementGrade(const int amount) {
    _grade -= amount;
    if (_grade < 1) {
        throw GradeTooHighException();
    }
}

void Bureaucrat::decrementGrade() {
    _grade++;
    if (_grade > 150) {
        throw GradeTooLowException();
    }
}

void Bureaucrat::decrementGrade(const int amount) {
    _grade += amount;
    if (_grade > 150) {
        throw GradeTooLowException();
    }
}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::signForm(Form form) const {
    form.beSigned(*this);
}

std::out_of_range Bureaucrat::GradeTooHighException() const {
    return std::out_of_range(_name + ", bureaucrate grade is too high!");
}

std::out_of_range Bureaucrat::GradeTooLowException() const {
    return std::out_of_range(_name + ", bureaucrate grade is too low!");
}

Bureaucrat::~Bureaucrat() {
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &bureaucrat) {
    output << bureaucrat.getName() + "{" << bureaucrat.getGrade() << "}";
    return output;
}
