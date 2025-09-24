# pragma once

#include <string>
#include <iostream>

#include "../inc/Form.hpp"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat( const std::string name, int grade );
		Bureaucrat( const Bureaucrat& copy );
		Bureaucrat& operator=( const Bureaucrat& copy );
		~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade(); //-1
	void		decrementGrade(); //+1
	void		signForm( Form& form ); //circular dependency???

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
std::ostream& operator<<( std::ostream& os, const Bureaucrat& bureaucrat );