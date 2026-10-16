#include "RobotomyRequestForm.hpp"

#include <cstdlib>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequest", 72, 45, "DefaultTarget") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &other) {
	if (&other == this)
		return *this;
	setTarget(other.getTarget());
	setSigned(other.getSigned());
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequest", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name,
                                         const std::string &target)
    : AForm(name, 72, 45, target) {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	checkExecutor(executor);

	std::cout << "*drill noise*" << std::endl;
	if (rand() % 2) {
		std::cout << getTarget() << " has been robotomized" << std::endl;
	} else {
		std::cout << "Failed robotomy on " << getTarget() << std::endl;
	}
}

AForm *RobotomyRequestForm::create(const std::string &name,
                                   const std::string &target) const {
	return new RobotomyRequestForm(name, target);
}

RobotomyRequestForm::~RobotomyRequestForm() {}
