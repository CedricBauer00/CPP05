# pragma once

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;
    public:
        AForm();
        AForm( const std::string name, int gradeToSign, int gradeToExecute );
        AForm( const AForm& copy );
        AForm& operator=( const AForm& copy );
        virtual ~AForm();
    
        std::string     getAFormName() const;
        bool            getIsSigned() const;
        int             getGradeToSign() const;
        int             getGradeToExecute() const;
        void            beSigned( const Bureaucrat& bureaucrat ); // Form wird signiert wenn Grade hoch genug
        virtual void    execute( Bureaucrat const & executor ) const = 0; // <- pure virtual
        
        class FormNotSignedException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<( std::ostream& os, const AForm& form );