#include "../inc/Form.hpp"

Form::Form() : _name("Defualt"),  _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout <<"\033[32mDefault Form has been constructed!\033[0m" << std::endl;
}

Form::Form( const std::string name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 
{
    std::cout << "\033[92mParametric form constructor has been called!\033[0m" << std::endl;
    if (_gradeToSign > 150)
        throw (GradeTooLowException());
    if (_gradeToSign < 1)
        throw (GradeTooHighException());
    
    if (_gradeToExecute > 150)
        throw (GradeTooLowException());
    if (_gradeToExecute < 1)
        throw (GradeTooHighException());
}

Form::Form( const Form& copy ) : _name( copy._name ), _isSigned( copy._isSigned ), _gradeToSign( copy._gradeToSign ), _gradeToExecute( copy._gradeToExecute )
{
    std::cout << "\033[34mForm copy constructor has been called!\033[0m" << std::endl;
}

Form& Form::operator=( const Form& copy )
{
    std::cout << "\033[94mForm assignment operator has been called!\033[0m" << std::endl;
    if ( this != &copy )
    {
        _isSigned = copy._isSigned;
    }
    return ( *this );
}

Form::~Form()
{
    std::cout << "\033[31mDestructor has been called!\033[0m" << std::endl;
}

std::ostream& operator<<( std::ostream& os, const Form& form )
{
    os << "\033[36mForm: " << form.getFormName()
        << "; _gradeToSign = " << form.getGradeToSign()
        << "; _gradeToExecute = " << form.getGradeToExecute()
        << "; isSigned = " << form.getIsSigned()
        << ";\033[0m" << std::endl;
    return ( os );
}

void    Form::beSigned( const Bureaucrat& bureaucrat )
{
    if (bureaucrat.getGrade() > _gradeToSign )
        throw (GradeTooLowException());
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("\033[35mGrade is too high. Grade must be between 1 and 150.\033[0m");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("\033[33mGrade is too low. Grade must be between 1 and 150.\033[0m");
}

std::string Form::getFormName() const
{
    return (_name);
}

bool Form::getIsSigned() const
{
    return (_isSigned);
}

int Form::getGradeToSign() const
{
    return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (_gradeToExecute);
}