#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Default Intern constructor!" << std::endl;
}

Intern::Intern( const Intern& copy )
{
    ( void )copy;
    std::cout << "Copy Intern constructor!" << std::endl;
}

Intern& Intern::operator=( const Intern& copy)
{
    std::cout << "Assignment Intern operator!" << std::endl;
    if ( this != &copy ) {}
    return ( *this );
}

Intern::~Intern()
{
    std::cout << "Destructor Intern called!" << std::endl;
}

// Functions being pointed to

AForm*  createShrubbery( const std::string& target )
{
    return ( new ShrubberyCreationForm( target ) );
}

AForm*  createRobotomy( const std::string& target )
{
    return ( new RobotomyRequestForm( target ) );
}

AForm*  createPresidential( const std::string& target )
{
    return ( new PresidentialPardonForm( target ) );
}

AForm* Intern::makeForm( const std::string formName, const std::string target )
{
    std::string formNameString[] = { "shrubbery creation", "robotomy request", "presidential pardon" };

    // ReturnType   ( *pointerName )( Parameter1, Parameter2 ) = &functionName;
    AForm*  ( *FormFunctions[] )( const std::string& ) = { createShrubbery, createRobotomy, createPresidential };

    for ( int i = 0; i < 3; i++)
    {
        if ( formNameString[i] == formName ) // if formName (input from functino call) matches one of the 3 elements of the string
        {
            std::cout << "Intern creates "
                        << formName
                        << std::endl;
            return ( FormFunctions[i]( target ) ); //call the certain function with the according function pointer index
        }    
    }
    std::cout << "\033[38;5;196mError:\033[0m Unknown form name '"
                << formName
                << "'"
                << std::endl;
    return ( nullptr );
}
