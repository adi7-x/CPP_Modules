#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal constructed!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed!" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "* WrongAnimal generic sound *" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}
