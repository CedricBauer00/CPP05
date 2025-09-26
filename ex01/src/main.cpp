#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{
    try
    {
        Bureaucrat  alfred("Alfred", 100);
        Form        contract( "Contract", 100, 50);
        std::cout   << "Before signing: "
                    << contract 
                    << std::endl;
        alfred.signForm( contract );
        std::cout   << "After signing: "
                    << contract 
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
        std::cout << e.what() << '\n';
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
    try
    {
        std::cout << "\n--- Testing Form copy and assignment operator ---\n" << std::endl;
        Bureaucrat  doc("Doc", 20);
        Form Ticket("Ticket", 50, 25);
        Form copyTicket(Ticket);
        Form assignmentForm("Temp", 150, 150);
        assignmentForm = Ticket;

        std::cout << "-------Before signing--------" << std::endl;
        std::cout << "Original Ticket: " << Ticket << std::endl;
        std::cout << "CopyTicket: " << copyTicket << std::endl;
        std::cout << "AssingmentTicket: " << assignmentForm << std::endl;
        
        doc.signForm(Ticket);

        std::cout << "-------After signing--------" << std::endl;
        std::cout << "Original Ticket: " << Ticket << std::endl;
        assignmentForm = Ticket;
        std::cout << "AssingmentTicket: " << assignmentForm << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    return (0);
}
