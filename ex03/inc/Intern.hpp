# pragma once
#include <string>
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
    public:
        Intern();
        Intern( const Intern& copy );
        Intern& operator=(  const Intern& copy );
        ~Intern();

        AForm* makeForm( const std::string formName, const std::string target );
};
