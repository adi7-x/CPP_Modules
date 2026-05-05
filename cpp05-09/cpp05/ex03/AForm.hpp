#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat;

class AForm {
private:
    const std::string	_name;
    bool				_signed;
    const int			_signGrade;
    const int			_execGrade;

public:
    AForm();
    AForm(const std::string& name, int signGrade, int execGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string&	getName() const;
    bool				isSigned() const;
    int					getSignGrade() const;
    int					getExecGrade() const;

    void				beSigned(const Bureaucrat& bureaucrat);
    void				execute(const Bureaucrat& executor) const;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

protected:
    virtual void		executeAction() const = 0;

private:
    void				validateGrade(int grade);
};

std::ostream&	operator<<(std::ostream& out, const AForm& form);

#endif