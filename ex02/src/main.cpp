#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

int main()
{
    std::cout << "\n\033[36m----------- Robotomy Tests -----------\n\033[0m" << std::endl;

    try
    {
        Bureaucrat              Alfred( "Alfred", 10 );
        ShrubberyCreationForm   Plant( "Garden" );
        
        Alfred.signForm( Plant );
        Alfred.executeForm( Plant );

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

        srand( time( NULL ) );
        Doc.signForm( Robot );
        Doc.executeForm( Robot );
    }
    catch( Bureaucrat::GradeTooHighException& e )
    {
        std::cout << e.what() << std::endl;
    }
    catch( Bureaucrat::GradeTooLowException& e )
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
