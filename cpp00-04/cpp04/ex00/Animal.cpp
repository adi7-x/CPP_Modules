#include "Animal.hpp"

Animal::Animal() : type("") {
    std::cout << "Animal constructed!" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destroyed!" << std::endl;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "* Generic animal sound *" << std::endl;
}
