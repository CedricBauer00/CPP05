#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm( "Shrubbery Creation", 145, 137), _target( "DefaultPlace" ) 
{
    std::cout << "Default shrubbery constructor!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm ( const std::string target ) 
    : AForm( "Shrubbery Creation", 145, 137 ), _target(target)
{
    std::cout << "Parametric shrubbery constructor!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& copy )
    : AForm( copy ), _target( copy._target)
{
    std::cout << "Copy shrubbery constructor!" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& copy )
{
    std::cout << "Assignment shrubbery operator called!" << std::endl;
    if ( this != &copy )
    {
        AForm::operator=(copy);
        this->_target = copy._target;
    }
        return ( *this );
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor shrubbery!" << std::endl;
    //AForm wird automatisch destructed
}

std::string ShrubberyCreationForm::getTarget() const
{
    return ( _target );
}

void    ShrubberyCreationForm::execute( const Bureaucrat& executor ) const
{
    if ( this->getIsSigned() != 1 )
        throw ( AForm::FormNotSignedException() );
    
    if ( executor.getGrade() > this->getGradeToExecute() )
        throw ( AForm::GradeTooLowException() );
    
    std::string fileName = _target + "_shrubbery";
    std::ofstream file(fileName);
    file << "════════════════ MAGICAL TREE GROVE ════════════════" << '\n'
         << "                                                    " << '\n'
         << "    @@@@@@       ***       ^^^^^        &&&&&      " << '\n'
         << "   @@@@@@@@     *****     ^^^^^^^      &&&&&&&     " << '\n'
         << "  @@@@@@@@@@   *******   ^^^^^^^^^    &&&&&&&&&    " << '\n'
         << "   @@@@@@@@     *****     ^^^^^^^      &&&&&&&     " << '\n'
         << "    @@@@@@       ***       ^^^^^        &&&&&      " << '\n'
         << "      ||          |          |           |||       " << '\n'
         << "      ||          |          |           |||       " << '\n'
         << "   -------    -------    -------      -------      " << '\n'
         << "                                                   " << '\n'
         << "      ####        000         +++         $$$      " << '\n'
         << "     ######      00000       +++++       $$$$$     " << '\n'
         << "    ########    0000000     +++++++     $$$$$$$    " << '\n'
         << "     ######      00000       +++++       $$$$$     " << '\n'
         << "      ####        000         +++         $$$      " << '\n'
         << "       ||          |           |          ||       " << '\n'
         << "       ||          |           |          ||       " << '\n'
         << "    -------    -------     -------    -------      " << '\n'
         << "                                                   " << '\n'
         << "     🌟 Eight Different Tree Species! 🌟           " << std::endl;

}
