#include "ShrubberyCreationForm.hpp"

std::string	ShrubberyCreationForm::tree =
"                                              .       \n\
                                   .         ;        \n\
      .              .              ;%     ;;         \n\
        ,           ,                :;%  %;          \n\
         :         ;                   :;%;'     .,   \n\
,.        %;     %;            ;        %;'    ,;     \n\
  ;       ;%;  %%;        ,     %;    ;%;    ,%'      \n\
   %;       %;%;      ,  ;       %;  ;%;   ,%;'       \n\
    ;%;      %;        ;%;        % ;%;  ,%;'         \n\
     `%;.     ;%;     %;'         `;%%;.%;'           \n\
      `:;%.    ;%%. %@;        %; ;@%;%'              \n\
         `:%;.  :;bd%;          %;@%;'                \n\
           `@%:.  :;%.         ;@@%;'                 \n\
             `@%.  `;@%.      ;@@%;                   \n\
               `@%%. `@%%    ;@@%;                    \n\
                 ;@%. :@%%  %@@%;                     \n\
                   %@bd%%%bd%%:;                      \n\
                     #@%%%%%:;;                       \n\
                     %@@%%%::;                        \n\
                     %@@@%(o);  . '                   \n\
                     %@@@o%;:(.,'                     \n\
                 `.. %@@@o%::;                        \n\
                    `)@@@o%::;                        \n\
                     %@@(o)::;                        \n\
                    .%@@@@%::;                        \n\
                    ;%@@@@%::;.                       \n\
                   ;%@@@@%%:;;;.                      \n\
               ...;%@@@@@%%:;;;;,..                   \n";

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	:Form("Shrubberycreation", 145, 137), target(target)
{}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref)
	:Form(ref.getName(), ref.getSignGrade(), ref.getExecGrade()), target(ref.target)
{}
ShrubberyCreationForm::~ShrubberyCreationForm()
{}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
	(void)ref;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw	ShrubberyCreationForm::FormNotSignedException();
	if (this->canGetSign(executor))
		throw	ShrubberyCreationForm::GradeTooLowException();
	std::ofstream fs(this->target + "_shrubbery");
	if (fs.fail())
		throw	ShrubberyCreationForm::FileCannotOpenException();
	fs << ShrubberyCreationForm::tree;
	fs.close();
}


