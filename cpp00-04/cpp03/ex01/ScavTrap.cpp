#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    _name = "Default_Scav";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " created by default constructor.\n";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructed with custom name.\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap " << _name << " created by copy constructor.\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap copy assignment operator called.\n";
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " is destroyed.\n";
}

void ScavTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _energyPoints--;
        std::cout << "ScavTrap " << _name << " ferociously attacks " << target
                  << ", causing " << _attackDamage << " points of damage!\n";
    } else {
        std::cout << "ScavTrap " << _name << " can't attack! No energy or is dead.\n";
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " has entered Gate Keeper mode.\n";
}
