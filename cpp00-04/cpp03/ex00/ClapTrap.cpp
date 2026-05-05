#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
    : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
        std::cout << _name << " is created successfully! with :\n";
        std::cout << "       |-> hitPoints: " << _hitPoints << "\n";
        std::cout << "       |-> energyPoints: " << _energyPoints << "\n";
        std::cout << "       |-> attackDamage: " << _attackDamage << "\n"; 
    }


ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
        std::cout << "\n" << _name << " is created successfully! with :\n";
        std::cout << "       |-> hitPoints: " << _hitPoints << "\n";
        std::cout << "       |-> energyPoints: " << _energyPoints << "\n";
        std::cout << "       |-> attackDamage: " << _attackDamage << "\n"; 
    }

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
        std::cout << "Copy Constructor called!" << _name << std::endl;
        std::cout << "       |-> hitPoints: " << _hitPoints << "\n";
        std::cout << "       |-> energyPoints: " << _energyPoints << "\n";
        std::cout << "       |-> attackDamage: " << _attackDamage << "\n"; 

}

ClapTrap::~ClapTrap() {
    std::cout << "\n-> " << _name << " is destroyed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "Copy assignmenr operator called!" << std::endl;

    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return(*this);
}

void ClapTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    } else {
        std::cout << "ClapTrap "  << _name << " can't attack (not enough energy or hit points)!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    _hitPoints = _hitPoints - amount;
    if (_hitPoints <= (int)amount) {
        _hitPoints = 0;
    } else {
        _hitPoints -= amount;
    }
    
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " has died!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _energyPoints--; 
        _hitPoints += amount;

        std::cout << "ClapTrap " << _name << " repairs itself for "
                  << amount << " hit points!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " can't repair itself "
                  << "(not enough energy or hit points)!" << std::endl;
    }
}
