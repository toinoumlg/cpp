#include "Form.hpp"
#include "Bureaucrat.hpp"

void test_forms(Bureaucrat &bureaucrat) {
    Form test("First", 151, 120);
    try {
        bureaucrat.signForm(test);
        std::cout << bureaucrat << " signed " << test;
    } catch (std::exception &e) {
        std::cerr << bureaucrat << " couldn't sign " << test << " because "
            << e.what()<< std::endl;
    }

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
