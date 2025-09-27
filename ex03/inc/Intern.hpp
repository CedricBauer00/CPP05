# pragma once
#include <string>
#include <iostream>

class AForm;

class Intern
{
    private:

    public:
        Intern();
        Intern();
        Intern();
        Intern& operator=();
        ~Intern();

        AForm* makeForm( const std::string formName, const std::string target );
}