#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat golem("Golem", 150);
		std::cout << golem++ << std::endl;
		std::cout << golem << std::endl;
		golem -= 30;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "-------------" << std::endl << std::endl;
	try {
		Bureaucrat golem2("Golem2", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "-------------" << std::endl << std::endl;
	try {
		Bureaucrat golem3("Golem3", 151);
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "-------------" << std::endl << std::endl;
	try {
		Bureaucrat pro("Pro", 1);
		pro -= 50;
		std::cout << pro << std::endl;
		pro += 60;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "-------------" << std::endl << std::endl;
	try {
		Bureaucrat buro("Buro", 75);
		std::cout << buro << std::endl;
		Bureaucrat buro1("Buro1", 150);
		buro = buro1;
		std::cout << buro << std::endl;
		buro.incrementGrade(100);
		std::cout << buro << std::endl;
		std::cout << buro1 << std::endl;
		buro.incrementGrade(50);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "-------------" << std::endl << std::endl;
	try {
		Bureaucrat worker("Worker", 150);
		Bureaucrat worker2 = Bureaucrat("Worker2", 130);
		worker += 149;
		std::cout << worker << std::endl;
		worker2 = 155;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "-------------" << std::endl << std::endl;
	try {
		Bureaucrat negative("Negative", -300);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "-------------" << std::endl << std::endl;
	try {
		Bureaucrat negative("Negative", 100);
		negative -= -100;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
