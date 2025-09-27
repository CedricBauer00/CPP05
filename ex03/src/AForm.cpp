#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm() : _name("Default"),  _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout <<"\033[32mDefault AForm has been constructed!\033[0m" << std::endl;
}

AForm::AForm( const std::string name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 
{
    std::cout << "\033[92mParametric Aform constructor: "
    << name
    << ", Aform; "
    << " grade to sign: "
    << gradeToSign
    << "; grade to execute: "
    << gradeToExecute
    << ". \033[0m"
    << std::endl;
    if (_gradeToSign > 150)
        throw ( GradeTooLowException() );
    if (_gradeToSign < 1)
        throw ( GradeTooHighException() );
    
    if (_gradeToExecute > 150)
        throw ( GradeTooLowException() );
    if (_gradeToExecute < 1)
        throw ( GradeTooHighException() );
}

AForm::AForm( const AForm& copy ) : _name( copy._name ), _isSigned( copy._isSigned ), _gradeToSign( copy._gradeToSign ), _gradeToExecute( copy._gradeToExecute )
{
    std::cout << "\033[34mAForm copy constructor has been called!\033[0m" << std::endl;
}

AForm& AForm::operator=( const AForm& copy )
{
    std::cout << "\033[94mAForm assignment operator has been called!\033[0m" << std::endl;
    if ( this != &copy )
    {
        _isSigned = copy._isSigned;
    }
    return ( *this );
}

AForm::~AForm()
{
    std::cout << "\033[31mAForm destructor! Destructed: \033[38;5;202m"
                << this->getAFormName()
                << "\033[0m!"
                << std::endl;
}

std::ostream& operator<<( std::ostream& os, const AForm& form )
{
    os << "\033[36mAForm: " << form.getAFormName()
        << "; _gradeToSign = " << form.getGradeToSign()
        << "; _gradeToExecute = " << form.getGradeToExecute()
        << "; isSigned = " << form.getIsSigned()
        << ";\033[0m";
    return ( os );
}

void    AForm::beSigned( const Bureaucrat& bureaucrat )
{
    if ( bureaucrat.getGrade() > _gradeToSign )
        throw ( GradeTooLowException() );
    _isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("\033[35mGrade is too high. Grade must be between 1 and 150.\033[0m");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("\033[33mGrade is too low.\033[0m");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("\033[31mForm not signed!\033[0m");
}

std::string AForm::getAFormName() const
{
    return ( _name );
}

bool AForm::getIsSigned() const
{
    return ( _isSigned );
}

int AForm::getGradeToSign() const
{
    return ( _gradeToSign );
}

int AForm::getGradeToExecute() const
{
    return ( _gradeToExecute );
}
