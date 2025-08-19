# pragma once

#include <string>
#include <iostream>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat( const std::string name, int grade );
	~Bureaucrat();
	std::string	getName();
	int			getgrade();
	void		incrementGrade(); //-1
	void		decrementGrade(); //+1

	class GradeTooHighException : public std::exception
	{
		public:
			const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char*	what() const throw();
	};
};
 //what implement (retrun val???)