#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook() : contactCount(0), nextIndex(0) {}

void PhoneBook::addContact() {
    Contact newContact;
    newContact.setInfo();

    if (!newContact.isValid()) {
        std::cout << "All fields must be filled. Contact not saved." << std::endl;
        return;
    }

    contacts[nextIndex] = newContact;
    nextIndex = (nextIndex + 1) % 8;

    if (contactCount < 8)
        contactCount++;

    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContact() const {
    if (contactCount == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }

    std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;

    for (int i = 0; i < contactCount; ++i) {
        contacts[i].displayContact(i);
    }

    std::cout << "Enter contact index to view details: ";
    std::string input;
    std::getline(std::cin, input);

    if (input.length() != 1 || input[0] < '0' || input[0] > '7') {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    int index = input[0] - '0';
    if (index >= contactCount) {
        std::cout << "No contact at this index." << std::endl;
        return;
    }

    contacts[index].displayFull();
}