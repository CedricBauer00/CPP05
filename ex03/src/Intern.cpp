#include "../inc/Intern.hpp"

Intern::Intern()
{
    std::cout << "Default Intern constructor!" << std::endl;
}

Intern::Intern( const Intern& copy )
{
    std::cout << "Copy Intern constructor!" << std::endl;
}

Intern& Intern::operator=( const Intern& copy)
{
    std::cout << "Assignment Intenr operator!" << std::endl;
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
    AForm   *returnForm = nullptr;

    for ( int i = 0; i < 3; i++)
    {
        std::cout << "Intern creates "
                    << formName
                    << std::endl;
        if ( formNameString[i] == formName ) // if formName (input from functino call) matches one of the 3 elements of the string
            returnForm = FormFunctions[i]( target ); //call the certain function with the according function pointer index
            return ( returnForm );
    }
    std::cout << "Error: Unkown form name '"
                << formName
                << "'"
                << std::endl;
    return ( returnForm );
}