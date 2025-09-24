#include "../inc/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat defauld;
        Bureaucrat a("Albrecht", 2);
        Bureaucrat b("Jens", 149);
        std::cout << defauld << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
}
