#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);

int main()
{
    std::cout << "--- Zombie from heap ---" << std::endl;
    Zombie* heapZombie = newZombie("Heapster");
    heapZombie->announce();
    delete heapZombie;

    std::cout << "--- Zombie from stack ---" << std::endl;
    randomChump("Stacky");
}