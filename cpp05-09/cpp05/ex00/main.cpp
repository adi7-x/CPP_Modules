#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== BUREAUCRAT TESTING 1 ===" << std::endl;

    // Test 1: Valid bureaucrat
    try {
        Bureaucrat bob("Bob", 1);
        std::cout << bob << std::endl;
        
        // Test increment/decrement
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;
        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "\033[31mError: \033[0m" << e.what() << std::endl;
    }

    // Test 2: Invalid grade - too high

    std::cout << "\n=== BUREAUCRAT TESTING 2 ===\n" << std::endl;

    try {
        Bureaucrat invalid("Invalid", 0);
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    
    // Test 3: Invalid grade - too low

    std::cout << "\n=== BUREAUCRAT TESTING 3 ===\n" << std::endl;
    
    try {
        Bureaucrat invalid("Invalid", 151);
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    // Test 4: Boundary increment exception

    std::cout << "\n=== BUREAUCRAT TESTING 4 ===\n" << std::endl;

    try {
        Bureaucrat ceo("CEO", 1);
        std::cout << ceo << std::endl;
        ceo.incrementGrade(); // Should throw
    }
    catch (std::exception& e) {
        std::cout << "Boundary error: " << e.what() << std::endl;
    }

    // Test 5: Boundary decrement exception
    
    std::cout << "\n=== BUREAUCRAT TESTING 5 ===\n" << std::endl;

    try {
        Bureaucrat intern("Intern", 150);
        std::cout << intern << std::endl;
        intern.decrementGrade(); // Should throw
    }
    catch (std::exception& e) {
        std::cout << "Boundary error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== BUREAUCRAT TESTING 6 ===\n" << std::endl;
    
    try {
        Bureaucrat original("Alice", 75);
        Bureaucrat copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
        
        Bureaucrat assigned("Charlie", -9);
        assigned = original;
        std::cout << "Assigned: " << assigned << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TESTS COMPLETED ===" << std::endl;
    return 0;
}
