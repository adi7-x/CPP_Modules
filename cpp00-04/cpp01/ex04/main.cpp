#include "FileReplacer.hpp"
#include <string>

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    const char* filename = argv[1];
    const char* s1 = argv[2];
    const char* s2 = argv[3];

    if (!s1 || s1[0] == '\0') {
        std::cerr << "Error: string1 cannot be empty" << std::endl;
        return 1;
    }

    replace_file(filename, s1, s2);

    return 0;
}