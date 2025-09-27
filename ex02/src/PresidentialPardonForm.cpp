#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm( "Presidential Pardon", 25, 5 ), _target( "Default President" )
{
    std::cout << "Default Presidential constructor! Constructed \033[38;5;202mDefault President\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string target )
    : AForm( "Presidential Pardon", 25, 5 ), _target( target )
{
    std::cout << "Parametric Presidential constructor! Constructed: \033[38;5;202m"
                << this->getTarget()
                << "\033[0m!"
                << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy )
    : AForm( copy ), _target( copy._target )
{
    std::cout << "Copy Presidential constructor! Copying: \033[38;5;202m"
                << copy.getTarget()
                << "\033[0m!"
                << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& copy ) 
{
    std::cout << "Assignment Presidential operator!" << std::endl;
    if ( this != &copy )
    {
        AForm::operator=( copy );
        this->_target = copy._target;
    }
    return ( *this );
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor Presidential called! Destructed: \033[38;5;202m"
                << this->getTarget()
                << "\033[0m!"
                << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
    return ( _target );
}

void    PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
    if ( this->getIsSigned() != 1 )
        throw ( AForm::FormNotSignedException() );
    if ( executor.getGrade() > this->getGradeToExecute() )
        throw ( AForm::GradeTooLowException() );

    std::cout << "\033[36m"
                << this->getTarget()
                << "\033[0m was pardoned by \033[38;5;202mZaphod Beeblebrox\033[0m"
                << std::endl;
}