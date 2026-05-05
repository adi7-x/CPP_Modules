#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    bool loadDatabase(const std::string& csvPath);
    bool hasRates() const;

    bool isValidDate(const std::string& date) const;
    bool parseRate(const std::string& s, double& out) const;
    bool getRateForDate(const std::string& date, double& out) const;

private:
    std::map<std::string, double> _rates;

    bool parseCsvLine(const std::string& line, std::string& date, double& rate) const;
    bool isLeap(int year) const;
    bool checkDateComponents(int y, int m, int d) const;
};

#endif
