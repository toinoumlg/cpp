#include <cstdlib>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	srand(time(0));
	try {
		Bureaucrat pro("Pro", 1);
		Bureaucrat noob("Noob", 150);

		RobotomyRequestForm robot("Einstein");
		ShrubberyCreationForm tree("little");
		PresidentialPardonForm president("Random");

		std::cout << noob << std::endl;
		std::cout << pro << std::endl;

		noob.signForm(robot);
		noob.executeForm(robot);
		noob.signForm(tree);
		noob.executeForm(tree);
		noob.signForm(president);
		noob.executeForm(president);

		pro.signForm(robot);
		noob.executeForm(robot);

		pro.executeForm(robot);
		pro.executeForm(robot);
		pro.executeForm(robot);
		pro.executeForm(robot);

		pro.signForm(tree);
		pro.executeForm(tree);
		pro.signForm(president);
		pro.executeForm(president);

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
}
