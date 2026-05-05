#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default Form"), _signed(false), _signGrade(LOWEST_GRADE), _execGrade(LOWEST_GRADE) {
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int signGrade, int execGrade) 
    : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
    std::cout << "Form parametric constructor called" << std::endl;
    validateGrade(signGrade);
    validateGrade(execGrade);
}

Form::Form(const Form& other) 
    : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
    std::cout << "Form assignment operator called" << std::endl;
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

Form::~Form() {
    std::cout << "Form destructor called for " << _name << std::endl;
}

const std::string& Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _signed;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecGrade() const {
    return _execGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade) {
        throw GradeTooLowException();
    }
    _signed = true;
    std::cout << _name << " has been signed by " << bureaucrat.getName() << std::endl;
}

void Form::validateGrade(int grade) {
    if (grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    if (grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high! (minimum grade is 1)";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low! (maximum grade is 150)";
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "Form " << form.getName() 
        << ", signed: " << (form.isSigned() ? "yes" : "no")
        << ", sign grade required: " << form.getSignGrade()
        << ", execution grade required: " << form.getExecGrade() << ".";
    return out;
}
