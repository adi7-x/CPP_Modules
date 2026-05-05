#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

static std::string trim(const std::string& s) {
    std::string::size_type start = 0;
    while (start < s.size() && (s[start] == ' ' || s[start] == '\t')) start++;
    std::string::size_type end = s.size();
    while (end > start && (s[end - 1] == ' ' || s[end - 1] == '\t')) end--;
    return s.substr(start, end - start);
}

static bool parseInputLine(const std::string& line, std::string& date, std::string& valueStr) {
    std::string::size_type pipe = line.find('|');
    if (pipe == std::string::npos) return false;
    date = trim(line.substr(0, pipe));
    valueStr = trim(line.substr(pipe + 1));
    return true;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange bex;
    if (!bex.loadDatabase("data.csv")) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    std::ifstream ifs(argv[1]);
    if (!ifs) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(ifs, line)) {
        if (line.empty()) continue;
        if (line == "date | value") continue; // header line as in example
        std::string date, valueStr;
        if (!parseInputLine(line, date, valueStr)) {
            std::cout << "Error: bad input => " << trim(line) << std::endl;
            continue;
        }
        if (!bex.isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        double value;
        {
            std::istringstream iss(valueStr);
            iss >> value;
            if (!iss || !iss.eof()) {
                std::cout << "Error: bad input => " << trim(line) << std::endl;
                continue;
            }
        }
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        double rate;
        if (!bex.getRateForDate(date, rate)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        double result = rate * value;
        std::cout << date << " => " << valueStr << " = " << result << std::endl;
    }

    return 0;
}
