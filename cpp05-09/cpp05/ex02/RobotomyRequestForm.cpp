#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request", 72, 45), _target("default") {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("Robotomy Request", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm parametric constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), _target(other._target) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

const std::string& RobotomyRequestForm::getTarget() const {
    return _target;
}

void RobotomyRequestForm::executeAction() const {
    std::cout << "* BZZZZZZT * WHIRRRRR * CLANK CLANK *" << std::endl;
    std::cout << "* DRILLING NOISES INTENSIFY *" << std::endl;
    std::cout << "* BZZT BZZT MECHANICAL SOUNDS *" << std::endl;
    
    static bool seedInitialized = false;
    if (!seedInitialized) {
        std::srand(std::time(NULL));
        seedInitialized = true;
    }
    
    if (std::rand() % 2) {
        std::cout << _target << " has been robotomized successfully! 🤖" << std::endl;
    } else {
        std::cout << "Robotomy of " << _target << " failed! Better luck next time..." << std::endl;
    }
}