#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog constructed!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called!" << std::endl;
    brain = new Brain(*other.brain);
    type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called!" << std::endl;
    if (this != &other) {
        type = other.type;
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destroyed!" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return brain->getIdea(index);
}
