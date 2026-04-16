#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test_forms(const Bureaucrat &bureaucrat) {
    RobotomyRequestForm robot("test");
    bureaucrat.signForm(robot);
    bureaucrat.executeForm(robot);
}

int main() {
    try {
        Bureaucrat golem("Golem", 150);
        Bureaucrat pro("Pro", 130);
        std::cout << golem++ << std::endl;
        std::cout << golem << std::endl;
        std::cout << pro << std::endl;
        test_forms(pro);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
