# pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm ( const std::string target );
        ShrubberyCreationForm( const ShrubberyCreationForm& copy );
        ShrubberyCreationForm& operator=( const ShrubberyCreationForm& copy );
        ~ShrubberyCreationForm();

        std::string getTarget() const;
        
        void execute( Bureaucrat const & executor ) const override;
};