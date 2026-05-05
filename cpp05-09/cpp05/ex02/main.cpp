#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "=== ABSTRACT FORMS AND POLYMORPHISM TESTING ===" << std::endl;

    // Test 1: Create different form types
    // try {
    //     std::cout << "\n--- Test 1: Creating Different Form Types ---" << std::endl;
        
    //     ShrubberyCreationForm shrub("garden");
    //     RobotomyRequestForm robot("Bender");
    //     PresidentialPardonForm pardon("Arthur Dent");
        
    //     std::cout << shrub << std::endl;
    //     std::cout << robot << std::endl;
    //     std::cout << pardon << std::endl;
    // }
    // catch (std::exception& e) {
    //     std::cout << "Error: " << e.what() << std::endl;
    // }

    // // Test 2: Polymorphic behavior with pointers
    // try {
    //     std::cout << "\n--- Test 2: Polymorphic Behavior ---" << std::endl;
        
    //     AForm* forms[] = {
    //         new ShrubberyCreationForm("home"),
    //         new RobotomyRequestForm("employee"),
    //         new PresidentialPardonForm("criminal")
    //     };
        
    //     for (int i = 0; i < 3; ++i) {
    //         std::cout << *forms[i] << std::endl;
    //     }
        
    //     // Clean up
    //     for (int i = 0; i < 3; ++i) {
    //         delete forms[i];
    //     }
    // }
    // catch (std::exception& e) {
    //     std::cout << "Error: " << e.what() << std::endl;
    // }

    //Test 3: Signing and executing ShrubberyCreationForm //
    try {
        std::cout << "\n--- Test 3: Shrubbery Creation Process ---" << std::endl;
        
        ShrubberyCreationForm shrubForm("backyard");
        Bureaucrat gardener("Gardener", 130); // Can sign (145) and execute (137)
        
        std::cout << "Before signing: " << shrubForm << std::endl;
        gardener.signForm(shrubForm);
        std::cout << "After signing: " << shrubForm << std::endl;
        
        gardener.executeForm(shrubForm);
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // // Test 4: Robotomy with multiple attempts (testing randomness) //
    // try {
    //     std::cout << "\n--- Test 4: Robotomy Attempts ---" << std::endl;
        
    //     RobotomyRequestForm robotForm("Victim");
    //     Bureaucrat scientist("Mad Scientist", 40); // Can sign (72) and execute (45)
        
    //     scientist.signForm(robotForm);
        
    //     std::cout << "\nAttempt 1:" << std::endl;
    //     scientist.executeForm(robotForm);
        
    //     std::cout << "\nAttempt 2:" << std::endl;
    //     scientist.executeForm(robotForm);
        
    //     std::cout << "\nAttempt 3:" << std::endl;
    //     scientist.executeForm(robotForm);
    // }
    // catch (std::exception& e) {
    //     std::cout << "Error: " << e.what() << std::endl;
    // }

    // // Test 5: Presidential pardon (highest security)
    // try {
    //     std::cout << "\n--- Test 5: Presidential Pardon ---" << std::endl;
        
    //     PresidentialPardonForm pardonForm("Ford Prefect");
    //     Bureaucrat president("President", 1); // Highest possible grade
        
    //     president.signForm(pardonForm);
    //     president.executeForm(pardonForm);
    // }
    // catch (std::exception& e) {
    //     std::cout << "Error: " << e.what() << std::endl;
    // }

    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
    return 0;
}