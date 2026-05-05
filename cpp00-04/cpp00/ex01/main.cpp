#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;
    std::cout << "Hello && Welcome to My Awesome PhoneBook!" << std::endl;

    while(1)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if(command == "ADD")
            phoneBook.addContact();
        else if(command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else
            std::cout << "Invalid command. Try again." << std::endl;
        
        if (std::cin.eof())
        {
            std::cout << "\EOF received. Exiting..." << std::endl;
            break;
        }
    }
    return(0);
}