#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
   public:
	virtual ~AForm();

	void beSigned(const Bureaucrat &bureaucrat);

	virtual void execute(const Bureaucrat &executor) const = 0;

	// Getters
	bool getSigned() const;

	const std::string &getName() const;

	int getReqSign() const;

	int getReqExec() const;

	const std::string &getTarget() const;

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

	class FormNeedSign : public std::exception {
	   public:
		FormNeedSign(const char *msg);
		const char *what() const throw();

	   private:
		const char *_message;
	};

   protected:
	AForm();
	AForm(const std::string &name, int sign, int exec,
	      const std::string &target);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	void checkExecutor(const Bureaucrat &executor) const;
	void setTarget(const std::string &target);
	void setSigned(bool sign);

   private:
	const std::string _name;
	bool _signed;
	const int _req_sign;
	const int _req_exec;
	std::string _target;
};

std::ostream &operator<<(std::ostream &output, AForm const &form);
