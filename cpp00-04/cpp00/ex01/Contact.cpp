#include "Contact.hpp"
#include <iostream>

void Contact::setInfo() {
    std::cout << "First Name: ";
    std::getline(std::cin, firstName);
    std::cout << "Last Name: ";
    std::getline(std::cin, lastName);
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Phone Number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Darkest Secret: ";
    std::getline(std::cin, darkestSecret);
}

bool Contact::isValid() const {
    return !firstName.empty() && !lastName.empty() && !nickname.empty()
        && !phoneNumber.empty() && !darkestSecret.empty();
}

std::string truncate(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    std::string padded = str;
    while (padded.length() < 10)
        padded = " " + padded;
    return padded;
}

void Contact::displayContact(int index) const {
    std::cout << "         " << index << "|";
    std::cout << truncate(firstName) << "|";
    std::cout << truncate(lastName) << "|";
    std::cout << truncate(nickname) << std::endl;
}

void Contact::displayFull() const {
    std::cout << "First Name: " << firstName << '\n';
    std::cout << "Last Name: " << lastName << '\n';
    std::cout << "Nickname: " << nickname << '\n';
    std::cout << "Phone Number: " << phoneNumber << '\n';
    std::cout << "Darkest Secret: " << darkestSecret << '\n';
}
