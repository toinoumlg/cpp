#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
   public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	ShrubberyCreationForm(const std::string& target);
	void execute(const Bureaucrat& executor) const;

	class InvalidFile : public std::exception {
	   public:
		InvalidFile(const char* msg);
		const char* what() const throw();

	   private:
		const char* _message;
	};
};