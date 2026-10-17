#include "PresidentialPardonForm.hpp"

#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardon", 25, 5, "DefaultTarget") {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &other) {
	if (&other == this)
		return *this;
	setTarget(other.getTarget());
	setSigned(other.getSigned());
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardon", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name,
                                               const std::string &target)
    : AForm(name, 25, 5, target) {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	checkExecutor(executor);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox"
	          << std::endl;
}

AForm *PresidentialPardonForm::create(const std::string &target) {
	return new PresidentialPardonForm(target);
}

PresidentialPardonForm::~PresidentialPardonForm() {}