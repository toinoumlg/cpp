#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
   public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	RobotomyRequestForm(const std::string& target);
	void execute(const Bureaucrat& executor) const;
};
