#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Form invalid("invalid", 155, 120);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "-------------" << std::endl << std::endl;
	try {
		Form invalid("invalid", -10, 120);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "-------------" << std::endl << std::endl;
	try {
		Form invalid("invalid", 100, 155);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "-------------" << std::endl << std::endl;
	try {
		Form invalid("invalid", 100, -15);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "-------------" << std::endl << std::endl;
	try {
		Form valid("valid", 130, 130);
		Form equal("equal", 150, 150);
		std::cout << valid << std::endl;
		Bureaucrat bureaucrat("Random", 150);
		bureaucrat.signForm(valid);
		bureaucrat.signForm(equal);
		std::cout << valid << std::endl;
		std::cout << equal << std::endl;
		bureaucrat = 1;
		bureaucrat.signForm(valid);
		std::cout << valid << std::endl;
		bureaucrat -= -1;
		bureaucrat -= 2;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
