#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat constructor has been called!" << std::endl;
	if (_grade < 1)
		throw (GradeTooHighException);
	if (_grade > 150)
		throw (GradeTooLowException);
	return (0);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor has been called!" << std::endl;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw (GradeTooHighException);
	else
		_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw (GradeTooLowException);
	else
		_grade++;
}
