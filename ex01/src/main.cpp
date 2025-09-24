#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{
    try
    {
        Bureaucrat  a("Albrecht", 100);
        Form        f( "Contract", 100, 50);
        std::cout   << "Before signing: "
                    << f 
                    << std::endl;
        a.signForm( f );
        std::cout   << "After signing: "
                    << f 
                    << std::endl;
    }
    catch ( Bureaucrat::GradeTooHighException &e ) //catch( std::exception &e )???
    {
        std::cout << e.what() << std::endl;
    }
    catch ( Bureaucrat::GradeTooLowException &e )
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat  intern( "Intern", 100);
        Form        confidentialinfo( "confidentialinfo", 5, 1 );
        std::cout   << "Before signing: "
                    << confidentialinfo
                    << std::endl;
        intern.signForm( confidentialinfo );
        std::cout   << "After signing: "
                    << confidentialinfo
                    << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
