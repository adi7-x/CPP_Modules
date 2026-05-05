#include "Intern.hpp"

const Intern::FormInfo Intern::_formTypes[3] = {
    {"shrubbery creation", &Intern::createShrubberyForm},
    {"robotomy request", &Intern::createRobotomyForm},
    {"presidential pardon", &Intern::createPardonForm}
};

const int Intern::_numFormTypes = 3;

Intern::Intern() {
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
    std::cout << "Intern copy constructor called" << std::endl;
    (void)other; // Suppress unused parameter warning
}

Intern& Intern::operator=(const Intern& other) {
    std::cout << "Intern assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    for (int i = 0; i < _numFormTypes; ++i) {
        if (_formTypes[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return _formTypes[i].creator(target);
        }
    }

    std::cout << "Intern doesn't know how to create \"" << formName << "\" form" << std::endl;
    throw UnknownFormException();
}


AForm* Intern::createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

const char* Intern::UnknownFormException::what() const throw() {
    return "Unknown form type requested from intern";
}