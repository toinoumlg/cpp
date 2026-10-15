#include "Bureaucrat.hpp"

#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("DefaultBureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, const int grade)
    : _name(name), _grade(grade) {
	if (_grade > 150)
		throw GradeTooLowException(name, grade);
	if (_grade < 1)
		throw GradeTooHighException(name, grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other.getName()), _grade(other.getGrade()) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this == &other)
		return *this;
	_grade = other.getGrade();
	return *this;
}
Bureaucrat &Bureaucrat::operator=(const int grade) {
	if (_grade == grade)
		return *this;
	if (grade > 150)
		throw GradeTooLowException(_name, grade);
	if (grade < 1)
		throw GradeTooHighException(_name, grade);
	_grade = grade;

	return *this;
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
	if (_grade - 1 < 1)
		throw GradeTooHighException(_name, _grade - 1);
	_grade--;
}

void Bureaucrat::incrementGrade(const int amount) {
	const int result = _grade - amount;
	if (result < 1)
		throw GradeTooHighException(_name, result);
	if (result > 150)
		throw GradeTooLowException(_name, result);
	_grade = result;
}

void Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw GradeTooLowException(_name, _grade + 1);
	_grade++;
}

void Bureaucrat::decrementGrade(const int amount) {
	const int result = _grade + amount;
	if (result > 150)
		throw GradeTooLowException(_name, result);
	if (result < 1)
		throw GradeTooHighException(_name, result);
	_grade = result;
}

void Bureaucrat::signForm(Form &form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (Form::GradeTooLowException &e) {
		std::cout << _name << " couldn't sign " << form.getName()
		          << " because: " << e.what() << std::endl;
	}
}

const std::string &Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

static std::string BuildExceptionMessage(const std::string &name,
                                         const int bad_grade,
                                         const char *reason) {
	std::stringstream sstream;
	sstream << "Bureaucrat " << name << " asked for a grade " << reason << " ("
	        << bad_grade << ')';
	return sstream.str();
}

Bureaucrat::GradeTooHighException::GradeTooHighException(
    const std::string &name, const int bad_grade) {
	_message = BuildExceptionMessage(name, bad_grade, "too high");
}
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return _message.c_str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &name,
                                                       const int bad_grade) {
	_message = BuildExceptionMessage(name, bad_grade, "too low");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return _message.c_str();
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::~Bureaucrat() {}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &bureaucrat) {
	output << bureaucrat.getName() << ", bureaucrat grade "
	       << bureaucrat.getGrade();
	return output;
}
