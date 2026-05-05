#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {
    std::cout << name << " has been destroyed. 💀" << std::endl;
}

void Zombie::announce() {
    std::cout << name << ": I'm happy in the heap 👻" << std::endl;
}

void Zombie::setName(std::string _name) {
    name = _name;
}