#include "../inc/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Albrecht", 0);
        Bureaucrat b("Jens", 200);
        a.incrementGrade();
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    if (!a.validateGrade())
    {
        std::cout << "Bureaucrat a has an invalid grade." << std::endl;
    }
}
