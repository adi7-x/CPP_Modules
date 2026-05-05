#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <deque>

int main()
{
    std::cout << "TEST WITH VECTOR" << std::endl;
    try
    {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);
        vec.push_back(50);

        std::cout << "FOUND: " << *easyfind(vec, 40) << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cout << "FOUND: " << *easyfind(vec, 0) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // std::cout << std::endl << "TEST WITH DEQUE" << std::endl;
    // try
    // {
    //     std::deque<int> deq;
    //     deq.push_back(1);
    //     deq.push_back(10);
    //     deq.push_back(20);
    //     deq.push_back(30);
    //     deq.push_back(40);
    //     deq.push_back(50);

    //     std::cout << "FOUND: " << *easyfind(deq, 40) << std::endl;
    //     std::cout << "--------------------------" << std::endl;
    //     std::cout << "FOUND: " << *easyfind(deq, 0) << std::endl;
    // }
    // catch (const std::exception& e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }

    return 0;
}
