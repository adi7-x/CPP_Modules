#include "Zombie.hpp"

int main()
{
    int N = 10;
    Zombie* horde = zombieHorde( N, " ZED 🧟");
    for (int i = 0; i < N; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
}