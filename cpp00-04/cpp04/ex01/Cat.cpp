#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "Cat constructed!" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called!" << std::endl;
    brain = new Brain(*other.brain);
    type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Dog assignment operator called!" << std::endl;
    if (this != &other) {
        type = other.type;
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destroyed!" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return brain->getIdea(index);
}
