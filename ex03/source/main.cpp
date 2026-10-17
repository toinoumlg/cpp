#include <cstdlib>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test_forms(const Bureaucrat &bureaucrat) {
	Intern intern;
	AForm *robot = intern.makeForm(" request", "robot");
	bureaucrat.signForm(*robot);
	bureaucrat.executeForm(*robot);
	delete robot;
}

int main() {
	srand(time(0));
	try {
		Bureaucrat golem("Golem", 150);
		Bureaucrat pro("Pro", 1);
		std::cout << golem++ << std::endl;
		std::cout << golem << std::endl;
		std::cout << pro << std::endl;
		test_forms(pro);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
