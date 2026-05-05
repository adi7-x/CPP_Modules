#include "FileReplacer.hpp"
#include <fstream>
#include <sstream>

void replace_file(const char* filename, const char* s1, const char* s2)
{
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error: Cannot open file" << std::endl;
        return;
    }

    std::string content;
    std::string line;

    while (std::getline(inFile, line))
    {
        content += line;
        if (!inFile.eof())
            content += "\n";
    }
    inFile.close();

    size_t pos = 0;
    std::string str_content = content;
    std::string str_s1 = s1;
    std::string str_s2 = s2;
    while ((pos = str_content.find(str_s1, pos)) != std::string::npos)
    {
        str_content = str_content.substr(0, pos) + str_s2 + str_content.substr(pos + str_s1.length());
        pos += str_s2.length();
    }

    std::string output_filename = std::string(filename) + ".replace";
    std::ofstream outFile(output_filename.c_str());
    if (!outFile) {
        std::cerr << "Error: Cannot create output file" << std::endl;
        return;
    }    

    outFile << str_content;
    outFile.close();
}