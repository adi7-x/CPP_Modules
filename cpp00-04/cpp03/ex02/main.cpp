#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
    std::cout << "===== Testing FragTrap =====" << std::endl;
    

    FragTrap frag("FR4G-TP");
    

    frag.attack("Enemy");
    frag.takeDamage(20);
    frag.beRepaired(10);
    

    frag.highFivesGuys();

    frag.attack("Enemy");
    frag.beRepaired(5);
    
    frag.takeDamage(200);
    frag.attack("Enemy"); 

    
    std::cout << "\n===== Program ending =====" << std::endl;
    return 0;
}