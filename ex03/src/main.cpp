#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int main()
{
    std::cout << "\n\033[36m----------- Shrubbery Tests -----------\n\033[0m" << std::endl;

    try
    {
        Bureaucrat              Alfred( "Alfred", 10 );
        ShrubberyCreationForm   Plant( "Garden" );
        ShrubberyCreationForm   copy( Plant );

        std::cout << std::endl;
        std::cout << copy << std::endl;

        Alfred.signForm( copy );
        Alfred.executeForm( copy );

    }
    catch( Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch( Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n\033[36m----------- Robotomy Tests -----------\n\033[0m" << std::endl;
    
    try
    {
        Bureaucrat          Doc( "Doc", 40 );
        RobotomyRequestForm Robot( "Alfred" );
        RobotomyRequestForm copy( Robot );

        std::cout << std::endl;
        std::cout << copy << std::endl;

        srand( time( NULL ) );
        Doc.signForm( copy );
        Doc.executeForm( copy );
    
    }
    catch( Bureaucrat::GradeTooHighException& e )
    {
        std::cout << e.what() << std::endl;
    }
    catch( Bureaucrat::GradeTooLowException& e )
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n\033[36m----------- Presidential Tests -----------\n\033[0m" << std::endl;

    try
    {
        Bureaucrat              President( "President", 5 );
        PresidentialPardonForm  Fool;
        PresidentialPardonForm  copy;

        std::cout << std::endl;
        std::cout << copy << std::endl;

        President.signForm( copy );
        President.executeForm( copy );
    
    }
     catch( Bureaucrat::GradeTooHighException& e )
    {
        std::cout << e.what() << std::endl;
    }
    catch( Bureaucrat::GradeTooLowException& e )
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n\033[36m----------- Intern Tests -----------\n\033[0m" << std::endl;

    try
    {    
        Bureaucrat  Alfred( "Alfred", 5 );
        std::cout << "\n\033[36m--- Intern shrub Tests ---\n\033[0m" << std::endl;

        Intern  intern;
        Intern  copy( intern );

        AForm* form1 = copy.makeForm( "shrubbery creation", "Garden" );
        if ( form1 )
        {
            std::cout << "✅ Shrubbery form created successfully! \033[36m~ main\033[0m" << std::endl;
            Alfred.signForm( *form1 );
            Alfred.executeForm( *form1 );
            delete ( form1 );
        }

        std::cout << "\n\033[36m--- Intern rob Tests ---\n\033[0m" << std::endl;


        AForm* form2 = intern.makeForm( "robotomy request", "Bender" );
        if ( form2 )
        {
            std::cout << "✅ Robotomy form created successfully! \033[36m~ main\033[0m" << std::endl;
            Alfred.signForm( *form2 );
            Alfred.executeForm( *form2 );
            delete ( form2 );
        }

        std::cout << "\n\033[36m--- Intern pres Tests ---\n\033[0m" << std::endl;


        AForm* form3 = intern.makeForm( "presidential pardon", "Fool" );
        if ( form3 )
        {
            std::cout << "✅ Presidential form created successfully! \033[36m~ main\033[0m" << std::endl;
            Alfred.signForm( *form3 );
            Alfred.executeForm( *form3 );
            delete ( form3 );
        }

        std::cout << "\n\033[36m--- Intern Invalid Form Tests ---\n\033[0m" << std::endl;


        AForm* form4 = intern.makeForm( "invalid Form", "Target" );
        if ( !form4 )
            std::cout << "✅ Invalid form correctly returned nullptr! \033[36m~ main\033[0m" << std::endl;
        
    }
    catch( Bureaucrat::GradeTooHighException& e )
    {
        std::cerr << e.what() << std::endl;
    }
    catch( Bureaucrat::GradeTooLowException& e )
    {
        std::cerr << e.what() << std::endl;
    }
    
    return (0);
}
