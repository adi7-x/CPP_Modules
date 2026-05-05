#include "PresidentialPardonForm.hpp"

// Orthodox Canonical Form

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Pardon", 25, 5), _target("default") {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
    : AForm("Presidential Pardon", 25, 5), _target(target) {
    std::cout << "PresidentialPardonForm parametric constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
    : AForm(other), _target(other._target) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

// Getter

const std::string& PresidentialPardonForm::getTarget() const {
    return _target;
}

// Protected method - implementation of pure virtual function

void PresidentialPardonForm::executeAction() const {
    std::cout << "📜 PRESIDENTIAL PARDON 📜" << std::endl;
    std::cout << "By the power vested in me by the Galactic Government," << std::endl;
    std::cout << "I, Zaphod Beeblebrox, President of the Galaxy," << std::endl;
    std::cout << "do hereby grant a full and unconditional pardon to " << _target << "." << std::endl;
    std::cout << "All charges are hereby dismissed and expunged from the record." << std::endl;
    std::cout << "Go forth and sin no more (or at least don't get caught)!" << std::endl;
    std::cout << "🌌 ⭐ 🚀" << std::endl;
}