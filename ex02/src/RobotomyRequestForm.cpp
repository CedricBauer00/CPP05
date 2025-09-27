#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm( "Robotomy Creation", 72, 45), _target( "Default Robotomy" )
{
    std::cout << "Default robotomy constructor!" << std::endl; 
}

RobotomyRequestForm::RobotomyRequestForm( const std::string target )
    : AForm( "Robotomy Creation", 72, 45 ), _target( target ) 
{
    std::cout << "Parametric robotomy constructor!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy )
    : AForm( copy ), _target( copy._target )
{
    std::cout << "Copy robotomy constructor!" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& copy )
{
    std::cout << "Assginment robotomy constructor!" << std::endl;
    if ( this != &copy )
    {
        AForm::operator=( copy );

        this->_target = copy._target;
    }
    return ( *this );
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor robotomy called! Destructed: \033[38;5;202m"
                << this->getTarget()
                << "\033[0m!"
                << std::endl;
}

void    RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
    if ( this->getIsSigned() != 1 )
        throw ( AForm::FormNotSignedException() );
    if (executor.getGrade() > this->getGradeToExecute() )
        throw ( AForm::GradeTooLowException() );
    
    std::cout << "DRILLING NOISES: Brrrr*r*r*r**r**r! ";            
    if ( rand() % 2 ) //etweder diese message zu einer 50 % chance:
    {
        std::cout << "\033[36m"
                    << this->getTarget()
                    << "\033[0m has been \033[33mrobotomized successfully!\033[0m"
                    << std::endl;
    }    
    else //oder diese zu 50 %
        std::cout << "Robotoisation \033[33mfailed!!\033[0m" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
    return ( _target );
}
