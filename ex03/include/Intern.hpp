#pragma once
#include "AForm.hpp"

class Intern {
   public:
	static AForm *makeForm(const std::string &name, const std::string &target);

   private:
	typedef AForm *(*FormConstructor)(const std::string &);

	struct FormCreator {
		const char *name;
		FormConstructor handler;
	};

	static FormCreator _forms_type[];

	class InvalidForm : public std::exception {
	   public:
		InvalidForm(const char *msg);
		const char *what() const throw();

	   private:
		const char *_message;
	};
};
