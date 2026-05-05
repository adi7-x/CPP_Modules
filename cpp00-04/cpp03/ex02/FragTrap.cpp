#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    
    std::cout << "FragTrap default constructor called for " << _name << std::endl;
    std::cout << "       |-> hitPoints updated to: " << _hitPoints << "\n";
    std::cout << "       |-> energyPoints updated to: " << _energyPoints << "\n";
    std::cout << "       |-> attackDamage updated to: " << _attackDamage << "\n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    
    std::cout << "FragTrap named constructor called for " << _name << std::endl;
    std::cout << "       |-> hitPoints updated to: " << _hitPoints << "\n";
    std::cout << "       |-> energyPoints updated to: " << _energyPoints << "\n";
    std::cout << "       |-> attackDamage updated to: " << _attackDamage << "\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called for " << _name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

void FragTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    } else {
        std::cout << "FragTrap " << _name << " can't attack (not enough energy or hit points)!" << std::endl;
    }
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " enthusiastically requests a high five from everyone!" << std::endl;
}
