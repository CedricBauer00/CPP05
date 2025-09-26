#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main()
{
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
    return (0);
}
