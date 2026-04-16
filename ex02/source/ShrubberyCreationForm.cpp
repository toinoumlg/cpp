#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <sys/stat.h>

#include "Bureaucrat.hpp"

// https://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exists-using-standard-c-c11-14-17-c
bool exists(const std::string &filename) {
    struct stat buffer = {};
    return stat(filename.c_str(), &buffer) == 0;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const{
    if (!getSigned())
        throw FormNeedSign();
    if (executor.getGrade() > getReqExec())
        throw GradeTooLowException();
    std::string filename;
    filename = getName() + "_shrubbery.txt";

    if (exists(filename))
        throw FileAlreadyExists();
    std::ofstream file(filename.data());

    /* Make tree ? */
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name) : AForm(
    name, 145, 137) {
}

std::invalid_argument ShrubberyCreationForm::FileAlreadyExists() {
    return std::invalid_argument("provided name is already an existing file");
}
