#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat {
private:
    const std::string	_name;
    int					_grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string&	getName() const;
    int					getGrade() const;

    void				incrementGrade();
    void				decrementGrade();

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

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
