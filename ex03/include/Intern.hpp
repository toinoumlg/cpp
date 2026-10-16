#pragma once
#include "AForm.hpp"

class Intern {
   public:
	typedef AForm *(*FormConstructor)(const std::string &, const std::string &);

	struct FormCreator {
		const char *name;
		FormConstructor handler;
	};

	AForm *makeForm(const std::string &name, const std::string &target);
	static std::invalid_argument InvalidFormType();

	static FormCreator _forms_type[];
};
