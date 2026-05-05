#include "ClapTrap.hpp"

int main() {
    std::cout << "Creating robots...\n";
    ClapTrap robotA("Alpha");
    ClapTrap robotB("Beta");

    std::cout << "\nAttacking and taking damage...\n";
    robotA.attack("Beta");
    robotB.takeDamage(3);

    std::cout << "\nRepairing...\n";
    robotB.beRepaired(5);

    std::cout << "\nCopy construction...\n";
    ClapTrap robotC(robotA);

    std::cout << "\nAssignment operator...\n";
    robotC = robotB;

    std::cout << "\nTesting zero HP behavior...\n";
    robotB.takeDamage(100);  // Should die
    robotB.attack("Alpha");  // Shouldn't attack
    robotB.beRepaired(10);   // Shouldn't repair

    std::cout << "\nEnd of main.\n";
    return 0;
}
