#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"



int main() {
    std::cout << "---- Testing Animal, Dog, and Cat ----" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << "Cat sound: ";
    i->makeSound();
    
    std::cout << "Dog sound: ";
    j->makeSound();

    delete j;
    delete i;

    std::cout << "\n---- Testing WrongAnimal and WrongCat ----" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;
    
    std::cout << "WrongCat sound through WrongAnimal pointer: ";
    wrongCat->makeSound();
    
    std::cout << "WrongAnimal sound: ";
    wrongMeta->makeSound();
    

    WrongCat directWrongCat;
    std::cout << "WrongCat sound through direct object: ";
    directWrongCat.makeSound();
    
    delete wrongMeta;
    delete wrongCat;

    return 0;
}