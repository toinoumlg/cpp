#include "Form.hpp"

#include "Bureaucrat.hpp"

Form::Form()
    : _name("DefaultForm"), _signed(false), _req_sign(150), _req_exec(150) {}

Form::Form(const std::string &name, const int sign, const int exec)
    : _name(name), _signed(false), _req_sign(sign), _req_exec(exec) {
	if (_req_sign < 1 || _req_exec < 1)
		throw GradeTooHighException(name, _req_sign, _req_exec);
	if (_req_sign > 150 || _req_exec > 150)
		throw GradeTooLowException(name, _req_sign, _req_exec);
}

Form::Form(const Form &other)
    : _name(other.getName()),
      _signed(other.getSigned()),
      _req_sign(other.getReqSign()),
      _req_exec(other.getReqExec()) {}

Form &Form::operator=(const Form &other) {
	if (this == &other)
		return *this;
	_signed = other.getSigned();
	return *this;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= _req_sign)
		_signed = true;
	else
		throw GradeTooLowException("bureaucrat grade too low");
}

bool Form::getSigned() const {
	return _signed;
}

const std::string &Form::getName() const {
	return _name;
}

int Form::getReqSign() const {
	return _req_sign;
}

int Form::getReqExec() const {
	return _req_exec;
}

static std::string BuildMessage(const std::string &name, const int req_sign,
                                const int req_exec, const std::string &reason) {
	std::stringstream stream;
	stream << "Form " << name << " required grade are out of range: " << reason
	       << " {" << req_sign << ';' << req_exec << '}';
	return stream.str();
}

Form::GradeTooHighException::GradeTooHighException(const std::string &name,
                                                   const int req_sign,
                                                   const int req_exec) {
	_message = BuildMessage(name, req_sign, req_exec, "too high");
}

const char *Form::GradeTooHighException::what() const throw() {
	return _message.c_str();
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooLowException::GradeTooLowException(const std::string &name,
                                                 const int req_sign,
                                                 const int req_exec) {
	_message = BuildMessage(name, req_sign, req_exec, "too low");
}

Form::GradeTooLowException::GradeTooLowException(const char *msg) {
	_message = msg;
}

const char *Form::GradeTooLowException::what() const throw() {
	return _message.c_str();
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::~Form() {}

std::ostream &operator<<(std::ostream &output, Form const &form) {
	output << "Form " << form.getName() << "{" << form.getReqSign() << ";"
	       << form.getReqExec() << "} is " << (form.getSigned() ? "" : "not ")
	       << "signed";
	return output;
}
