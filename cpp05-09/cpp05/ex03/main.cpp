#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    std::cout << "=== INTERN FACTORY TESTS ===" << std::endl;

    try {
        Intern intern;
        Bureaucrat boss("Boss", 1);

        std::cout << "\n--- Test 1: Create Shrubbery Form ---" << std::endl;
        AForm* form1 = intern.makeForm("shrubbery creation", "garden");
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;

        std::cout << "\n--- Test 2: Create Robotomy Form ---" << std::endl;
        AForm* form2 = intern.makeForm("robotomy request", "Bender");
        boss.signForm(*form2);
        boss.executeForm(*form2);
        delete form2;

        std::cout << "\n--- Test 3: Try Unknown Form ---" << std::endl;
        AForm* form3 = intern.makeForm("unknown form", "target");
        delete form3;

    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}