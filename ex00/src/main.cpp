#include "../inc/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat defauld;
        Bureaucrat a("Albrecht", 2);
        Bureaucrat b("Jens", 148);
     
        std::cout << defauld << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
     
        a.incrementGrade();
        b.decrementGrade();
        b.decrementGrade();
        std::cout << a << std::endl;
        std::cout << b << std::endl;
    }
    catch ( Bureaucrat::GradeTooHighException &e )
    {
        std::cout << e.what() << std::endl;
    }
    catch ( Bureaucrat::GradeTooLowException &e )
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "\n--- Testing copy and assignment operator ---\n" << std::endl;
     
        Bureaucrat doc("Doc", 30);
        Bureaucrat copyDoc(doc);
        Bureaucrat assignemnt("AssignDoc", 150);
        assignemnt = doc;

        std::cout << "Original doc: " << doc << std::endl;
        std::cout << "Copy of doc: " << copyDoc << std::endl;
        std::cout << "Assingment: " << assignemnt << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
