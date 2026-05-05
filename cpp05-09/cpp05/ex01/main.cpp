#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "=== FORM AND BUREAUCRAT TESTING ===" << std::endl;

    // Test 1: Valid form creation and basic info
    try {
        std::cout << "\n--- Test 1: Form Creation ---" << std::endl;
        Form contract("Employment Contract", 50, 25);
        std::cout << contract << std::endl;
        
        Bureaucrat manager("Manager", 40);
        std::cout << manager << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 2: Invalid form grades
    try {
        std::cout << "\n--- Test 2: Invalid Form Grades ---" << std::endl;
        Form invalidForm("Invalid", 0, 25); // Should throw
    }
    catch (Form::GradeTooHighException& e) {
        std::cout << "Caught form exception: " << e.what() << std::endl;
    }

    try {
        Form invalidForm2("Invalid2", 50, 151); // Should throw
    }
    catch (Form::GradeTooLowException& e) {
        std::cout << "Caught form exception: " << e.what() << std::endl;
    }

    // // Test 3: Successful form signing
    try {
        std::cout << "\n--- Test 3: Successful Form Signing ---" << std::endl;
        
        Form easyForm("Easy Form", 60, 60);
        Bureaucrat highRankBureaucrat("Boss", 20);
        
        std::cout << "Before signing:" << std::endl;
        std::cout << easyForm << std::endl;
        
        highRankBureaucrat.signForm(easyForm);
        
        std::cout << "After signing:" << std::endl;
        std::cout << easyForm << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // // Test 4: Failed form signing (grade too low)
    try {
        std::cout << "\n--- Test 4: Failed Form Signing ---" << std::endl;
        Form hardForm("Hard Form", 5, 1);
        Bureaucrat lowRankBureaucrat("Intern", 60);
        
        std::cout << "Before signing attempt:" << std::endl;
        std::cout << hardForm << std::endl;
        std::cout << lowRankBureaucrat << std::endl;
        
        lowRankBureaucrat.signForm(hardForm); // Should fail gracefully
        
        std::cout << "After failed signing attempt:" << std::endl;
        std::cout << hardForm << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    // // Test 6: Copy constructor and assignment
    // try {
    //     std::cout << "\n--- Test 6: Copy Constructor and Assignment ---" << std::endl;
    //     Form original("Original Form", 50, 25);
    //     Bureaucrat signer("Signer", 30);
        
    //     signer.signForm(original);
    //     std::cout << "Original: " << original << std::endl;
        
    //     Form copy(original);
    //     std::cout << "Copy: " << copy << std::endl;
        
    //     Form assigned("Different Form", 100, 75);
    //     std::cout << "Before assignment: " << assigned << std::endl;
    //     assigned = original; // Only signed status is copied
    //     std::cout << "After assignment: " << assigned << std::endl;
    // }
    // catch (std::exception& e) {
    //     std::cout << "Error: " << e.what() << std::endl;
    // }

    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
    return 0;
}