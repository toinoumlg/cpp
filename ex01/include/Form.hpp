#pragma once

#include <exception>
#include <iostream>
#include <sstream>

class Bureaucrat;

class Form {
   public:
	Form();

	Form(const std::string &name, int sign, int exec);

	Form(const Form &other);

	~Form();

	Form &operator=(const Form &other);

	void beSigned(const Bureaucrat &bureaucrat);

	// Getters

	bool getSigned() const;

	const std::string &getName() const;

	int getReqSign() const;

	int getReqExec() const;

	// Error
	class GradeTooHighException : public std::exception {
	   public:
		GradeTooHighException(const std::string &name, int req_sign,
		                      int req_exec);
		const char *what() const throw();
		~GradeTooHighException() throw();

	   private:
		std::string _message;
	};

	class GradeTooLowException : public std::exception {
	   public:
		GradeTooLowException(const std::string &name, int req_sign,
		                     int req_exec);
		GradeTooLowException(const char *msg);
		const char *what() const throw();
		~GradeTooLowException() throw();

	   private:
		std::string _message;
	};

   private:
	const std::string _name;
	bool _signed;
	const int _req_sign;
	const int _req_exec;
};

std::ostream &operator<<(std::ostream &output, Form const &form);
