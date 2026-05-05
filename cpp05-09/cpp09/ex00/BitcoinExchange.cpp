#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

static std::string trim(const std::string& s) {
    std::string::size_type start = 0;
    while (start < s.size() && (s[start] == ' ' || s[start] == '\t')) start++;
    std::string::size_type end = s.size();
    while (end > start && (s[end - 1] == ' ' || s[end - 1] == '\t')) end--;
    return s.substr(start, end - start);
}

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _rates(other._rates) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _rates = other._rates;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::hasRates() const { return !_rates.empty(); }

bool BitcoinExchange::isLeap(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::checkDateComponents(int y, int m, int d) const {
    if (y < 0 || m < 1 || m > 12 || d < 1) return false;
    static const int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int days = mdays[m - 1];
    if (m == 2 && isLeap(y)) days = 29;
    return d <= days;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.size() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) continue;
        if (date[i] < '0' || date[i] > '9') return false;
    }
    int y = std::atoi(date.substr(0,4).c_str());
    int m = std::atoi(date.substr(5,2).c_str());
    int d = std::atoi(date.substr(8,2).c_str());
    return checkDateComponents(y,m,d);
}

bool BitcoinExchange::parseRate(const std::string& s, double& out) const {
    std::istringstream iss(s);
    iss >> out;
    return iss && iss.eof();
}

bool BitcoinExchange::parseCsvLine(const std::string& line, std::string& date, double& rate) const {
    std::string::size_type comma = line.find(',');
    if (comma == std::string::npos) return false;
    date = trim(line.substr(0, comma));
    std::string value = trim(line.substr(comma + 1));
    if (!isValidDate(date)) return false;
    if (!parseRate(value, rate)) return false;
    return true;
}

bool BitcoinExchange::loadDatabase(const std::string& csvPath) {
    std::ifstream ifs(csvPath.c_str());
    if (!ifs) return false;
    std::string line;

    if (std::getline(ifs, line))
    {
        if (line.find("date") != std::string::npos && line.find("exchange") != std::string::npos)
        {
            //...next
        } 
        else 
        {
            std::string date; double rate;
            if (parseCsvLine(line, date, rate)) {
                _rates[date] = rate;
            }
        }
    }
    while (std::getline(ifs, line)) {
        if (line.empty()) continue;
        std::string date; double rate;
        if (parseCsvLine(line, date, rate)) {
            _rates[date] = rate;
        }
    }
    return !_rates.empty();
}

bool BitcoinExchange::getRateForDate(const std::string& date, double& out) const {
    if (!isValidDate(date)) return false;
    std::map<std::string,double>::const_iterator it = _rates.lower_bound(date);
    if (it != _rates.end() && it->first == date) {
        out = it->second;
        return true;
    }
    if (it == _rates.begin()) {
        return false;
    }
    --it;
    out = it->second;
    return true;
}
