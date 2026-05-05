#include "Array.hpp"
#include <string>

int main()
{
    // test with int 
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i * 10;

    std::cout << "a: ";
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    // ---- test deep copy ----
    Array<int> b(a);
    b[0] = 999;

    std::cout << "a[0]: " << a[0] << std::endl;
    std::cout << "b[0]: " << b[0] << std::endl;

    // ---- Test assignment ----
    Array<int> c;
    c = a;

    std::cout << "c[3]: " << c[3] << std::endl;

    // ---- Test out of range ----
    try {
        std::cout << a[100] << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // ---- Test with strings ----
    Array<std::string> s(3);
    s[0] = "Hello";
    s[1] = "World";
    s[2] = "!!!";

    std::cout << "Strings: ";
    for (unsigned int i = 0; i < s.size(); i++)
        std::cout << s[i] << " ";
    std::cout << std::endl;

    return 0;
}
