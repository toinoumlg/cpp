#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::FormCreator Intern::_forms_type[] = {
    {"shrubbery creation", &ShrubberyCreationForm::create},
    {"robotomy request", &RobotomyRequestForm::create},
    {"presidential pardon", &PresidentialPardonForm::create}};

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
	const int size = sizeof(_forms_type) / sizeof(_forms_type[0]);
	for (int i = 0; i < size; ++i) {
		if (name == _forms_type[i].name) {
			AForm* created = _forms_type[i].handler(target);
			std::cout << "Intern created " << *created << std::endl;
			return created;
		}
	}
	throw InvalidForm("invalid form");
}

Intern::InvalidForm::InvalidForm(const char* msg) {
	_message = msg;
}

const char* Intern::InvalidForm::what() const throw() {
	return _message;
}