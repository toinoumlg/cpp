#pragma once

#include <iostream>
#include <sstream>

class AForm;

class Bureaucrat {
   public:
	// Constructor
	Bureaucrat();

	Bureaucrat(const std::string &name, int grade);

	Bureaucrat(const Bureaucrat &other);

	Bureaucrat &operator=(const Bureaucrat &other);

	~Bureaucrat();

	// Operator overloads
	Bureaucrat &operator=(int grade);

	Bureaucrat &operator+=(int i);

	Bureaucrat operator++(int);

	Bureaucrat &operator++();

	Bureaucrat &operator-=(int i);

	Bureaucrat operator--(int);

	Bureaucrat &operator--();

	// Modifier
	void incrementGrade();

	void incrementGrade(int amount);

	void decrementGrade();

	void decrementGrade(int amount);

	// Form stuff

	void signForm(AForm &form) const;

	void executeForm(const AForm &form) const;

	// Getters
	const std::string &getName() const;

	int getGrade() const;

	// Errors
	class GradeTooHighException : public std::exception {
	   public:
		GradeTooHighException(const std::string &name, int grade);
		const char *what() const throw();
		~GradeTooHighException() throw();

	   private:
		std::string _message;
	};

	class GradeTooLowException : public std::exception {
	   public:
		GradeTooLowException(const std::string &name, int grade);
		const char *what() const throw();
		~GradeTooLowException() throw();

	   private:
		std::string _message;
	};

   private:
	const std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &output, Bureaucrat const &bureaucrat);
