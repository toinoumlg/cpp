#include "AForm.hpp"

#include <sstream>

#include "Bureaucrat.hpp"

AForm::AForm()
    : _name("AForm"), _signed(false), _req_sign(150), _req_exec(150) {}

AForm::AForm(const std::string &name, const int sign, const int exec,
             const std::string &target)
    : _name(name),
      _signed(false),
      _req_sign(sign),
      _req_exec(exec),
      _target(target) {
	if (_req_sign < 1 || _req_exec < 1)
		throw GradeTooHighException(name, _req_sign, _req_exec);
	if (_req_sign > 150 || _req_exec > 150)
		throw GradeTooLowException(name, _req_sign, _req_exec);
}

AForm::AForm(const AForm &other)
    : _name(other._name),
      _signed(other._signed),
      _req_sign(other._req_sign),
      _req_exec(other._req_exec),
      _target(other._target) {}

AForm &AForm::operator=(const AForm &other) {
	if (this == &other)
		return *this;
	_signed = other._signed;
	_target = other._target;
	return *this;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= _req_sign)
		_signed = true;
	else
		throw GradeTooLowException("grade too low");
}

bool AForm::getSigned() const {
	return _signed;
}

const std::string &AForm::getName() const {
	return _name;
}

void AForm::checkExecutor(const Bureaucrat &executor) const {
	if (!_signed)
		throw FormNeedSign("need to sign form");
	if (executor.getGrade() > _req_exec)
		throw GradeTooLowException("grade too low");
}

int AForm::getReqSign() const {
	return _req_sign;
}

int AForm::getReqExec() const {
	return _req_exec;
}
const std::string &AForm::getTarget() const {
	return _target;
}
void AForm::setTarget(const std::string &target) {
	_target = target;
}
void AForm::setSigned(bool sign) {
	_signed = sign;
}

static std::string BuildMessage(const std::string &name, const int req_sign,
                                const int req_exec, const std::string &reason) {
	std::stringstream stream;
	stream << "Form " << name << " required grade are out of range: " << reason
	       << " {" << req_sign << ';' << req_exec << '}';
	return stream.str();
}

AForm::GradeTooHighException::GradeTooHighException(const std::string &name,
                                                    const int req_sign,
                                                    const int req_exec) {
	_message = BuildMessage(name, req_sign, req_exec, "too high");
}

const char *AForm::GradeTooHighException::what() const throw() {
	return _message.c_str();
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

AForm::GradeTooLowException::GradeTooLowException(const std::string &name,
                                                  const int req_sign,
                                                  const int req_exec) {
	_message = BuildMessage(name, req_sign, req_exec, "too low");
}

AForm::GradeTooLowException::GradeTooLowException(const char *msg)
    : _message(msg) {}

const char *AForm::GradeTooLowException::what() const throw() {
	return _message.c_str();
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

AForm::FormNeedSign::FormNeedSign(const char *msg) : _message(msg) {}

const char *AForm::FormNeedSign::what() const throw() {
	return _message;
}

AForm::~AForm() {}

std::ostream &operator<<(std::ostream &output, AForm const &form) {
	output << "Form " << form.getName() << "{" << form.getReqSign() << ";"
	       << form.getReqExec() << "} is " << (form.getSigned() ? "" : "not ")
	       << "signed, target is " << form.getTarget();
	return output;
}
