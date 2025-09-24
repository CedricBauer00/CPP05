# pragma once

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;
    public:
        Form();
        Form( const std::string name, int gradeToSign, int gradeToExecute );
        Form( const Form& copy );
        Form& operator=( const Form& copy );
        ~Form();
    
        std::string getFormName() const;
        bool        getIsSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;
        void        beSigned( const Bureaucrat& bureaucrat ); // Form wird signiert wenn Grade hoch genug
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

std::ostream& operator<<( std::ostream& os, const Form& form );