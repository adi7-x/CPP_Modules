#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(T const &x)
{
    std::cout << x << " ";
}

template <typename T>
void increment(T &x)
{
    x = x + 1;
}

int main()
{
    std::cout << "---- Test with int ----" << std::endl;
    int arrInt[] = {1, 2, 3, 4, 5};

    std::cout << "Before increment: ";
    iter(arrInt, 5, printElement<int>);
    std::cout << std::endl;

    iter(arrInt, 5, increment<int>);

    std::cout << "After increment: ";
    iter(arrInt, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "\n---- Test with std::string ----" << std::endl;
    std::string arrStr[] = {"hello", "world", "42"};

    iter(arrStr, 3, printElement<std::string>);
    std::cout << std::endl;

    std::cout << "\n---- Test with const array ----" << std::endl;
    const int arrConst[] = {10, 20, 30};

    iter(arrConst, 3, printElement<int>);
    std::cout << std::endl;

    return 0;
}
