#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat;

class Form {
private:
    const std::string	_name;
    bool				_signed;
    const int			_signGrade;
    const int			_execGrade;

public:
    Form();
    Form(const std::string& name, int signGrade, int execGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    const std::string&	getName() const;
    bool				isSigned() const;
    int					getSignGrade() const;
    int					getExecGrade() const;

    void				beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

private:
    void				validateGrade(int grade);
};

std::ostream&	operator<<(std::ostream& out, const Form& form);

#endif
