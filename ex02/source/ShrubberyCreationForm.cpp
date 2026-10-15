#include "ShrubberyCreationForm.hpp"

#include <fstream>

#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreation", 145, 137, "DefaultTarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other) {
	if (&other == this)
		return *this;
	setTarget(other.getTarget());
	setSigned(other.getSigned());
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreation", 145, 137, target) {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	checkExecutor(executor);
	const std::string filename = getTarget() + "_shrubbery";

	std::ofstream file(filename.c_str());
	if (file.fail())
		throw InvalidFile("failed to open file");

	file << "     ccee88oo" << std::endl
	     << "  C8O8O8Q8PoOb o8oo" << std::endl
	     << " dOB69QO8PdUOpugoO9bD" << std::endl
	     << "CgggbU8OU qOp qOdoUOdcb" << std::endl
	     << "    6OuU  /p u gcoUodpP" << std::endl
	     << "      \\\\\\//  /douUP" << std::endl
	     << "        \\\\\\////" << std::endl
	     << "         |||/\\" << std::endl
	     << "         |||\\/" << std::endl
	     << "         |||||" << std::endl
	     << "   .....//||||\\...." << std::endl;

	file.close();
}

ShrubberyCreationForm::InvalidFile::InvalidFile(const char* msg)
    : _message(msg) {}

const char* ShrubberyCreationForm::InvalidFile::what() const throw() {
	return _message;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}