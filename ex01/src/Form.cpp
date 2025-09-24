#include "../inc/Form.hpp"

Form::Form() : _name("defualt_Name"),  _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout <<"\033[32mDefault Form has been constructed!\033[0m" << std::endl;
}

Form::Form( const std::string name, int isSigned, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(isSigned), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 
{
    std::cout << "\033[92mParametric form constructor has been called!\033[0m";
    if (_gradeToSign > 150)
        throw (GradeTooLowException());
    if (_gradeToSign < 1)
        throw (GradeTooHighException());
    
    if (_gradeToExecute > 150)
        throw (GradeTooLowException());
    if (_gradeToExecute < 1)
        throw (GradeTooHighException());
}