#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
   public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	PresidentialPardonForm(const std::string& target);
	void execute(const Bureaucrat& executor) const;
};
