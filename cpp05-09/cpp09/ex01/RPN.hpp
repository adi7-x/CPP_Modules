#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN {
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    bool evaluate(const std::string& expr, int& outResult) const;
};

#endif
