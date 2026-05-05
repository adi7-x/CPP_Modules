#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default AForm"), _signed(false), _signGrade(LOWEST_GRADE), _execGrade(LOWEST_GRADE) {
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int execGrade) 
    : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
    std::cout << "AForm parametric constructor called" << std::endl;
    validateGrade(signGrade);
    validateGrade(execGrade);
}

AForm::AForm(const AForm& other) 
    : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    std::cout << "AForm assignment operator called" << std::endl;
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destructor called for " << _name << std::endl;
}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _signed;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecGrade() const {
    return _execGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade) {
        throw GradeTooLowException();
    }
    _signed = true;
    std::cout << _name << " has been signed by " << bureaucrat.getName() << std::endl;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!_signed) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > _execGrade) {
        throw GradeTooLowException();
    }
    executeAction();
}

void AForm::validateGrade(int grade) {
    if (grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    if (grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high! (minimum grade is 1)";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low! (maximum grade is 150)";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm is not signed and cannot be executed!";
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << "Form " << form.getName() 
        << ", signed: " << (form.isSigned() ? "yes" : "no")
        << ", sign grade required: " << form.getSignGrade()
        << ", execution grade required: " << form.getExecGrade() << ".";
    return out;
}