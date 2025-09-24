#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150)
{
	std::cout << "\033[32mBureaucrat default constuctor has been called!\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name(name), _grade(grade)
{
	std::cout << "\033[92mBureaucrat constructor has been called!\033[0m" << std::endl;
	if (_grade < 1)
		throw (GradeTooHighException());
	if (_grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat( const Bureaucrat& copy ) : _name( copy._name ), _grade( copy._grade )
{
	std::cout << "\033[34mBureaucrat copy constructor has been called!\033[0m" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& copy )
{
	std::cout << "\033[94mBureaucrat assingment operator has been called!\033[0m" << std::endl;
	if ( this != &copy )
		_grade = copy._grade;
	return ( *this );
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[31mBureaucrat destructor has been called!\033[0m" << std::endl;
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& bureaucrat )
{
	os << "\033[36m" << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "!\033[0m";
	return ( os );
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw (GradeTooHighException());
	else
		_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw (GradeTooLowException());
	else
		_grade++;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\033[35mGrade is too low. Grade must be between 1 and 150.\033[0m");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\033[33mGrade is too high. Grade must be between 1 and 150.\033[0m");
}
