#include <iostream>
#include <string>

int main()
{
    std::string name = "HI THIS IS BRAIN";

    std::string* stringPTR = &name;
    std::string& stringREF = name;

    std::cout << "Memory address of the string:     " << &name << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    std::cout << "------------------------------------------------" << std::endl;

    std::cout << "Value of the string:           " << name << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return(0);
}
