#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "\n=== Creating ScavTrap ===\n";
    ScavTrap scav("Serena");

    std::cout << "\n=== Using attack() ===\n";
    scav.attack("EnemyBot");

    std::cout << "\n=== Using guardGate() ===\n";
    scav.guardGate();

    std::cout << "\n=== Taking damage and repairing ===\n";
    scav.takeDamage(30);
    scav.beRepaired(20);

    std::cout << "\n=== Trying to repair after death ===\n";
    scav.takeDamage(999);
    scav.beRepaired(10);

    std::cout << "\n=== Exiting main ===\n";
    return 0;
}
