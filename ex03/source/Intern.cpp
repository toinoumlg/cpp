#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::FormCreator Intern::_forms_type[] = {
    {"shrubbery request", &ShrubberyCreationForm::create},
    {"robotomy request", &RobotomyRequestForm::create},
    {"presidential request", &PresidentialPardonForm::create}};

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
	for (int i = 0; i < 3; i++) {
		if (name == _forms_type[i].name) {
			AForm* created = _forms_type[i].handler(name, target);
			this->*_forms_type[i].handler;
			std::cout << "Intern created " << *created << std::endl;
			return created;
		}
	}
	throw InvalidFormType();
}

std::invalid_argument Intern::InvalidFormType() {
	return std::invalid_argument("invalid form type");
}
