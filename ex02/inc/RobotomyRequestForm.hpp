# pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm( const std::string target );
        RobotomyRequestForm( const RobotomyRequestForm& copy );
        RobotomyRequestForm& operator=( const RobotomyRequestForm& copy );
        ~RobotomyRequestForm();

        std::string getTarget() const;

        void    execute( Bureaucrat const & executor ) const override;
};