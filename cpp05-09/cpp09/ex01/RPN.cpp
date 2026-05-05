#include "RPN.hpp"

#include <stack>
#include <sstream>

RPN::RPN() {}
RPN::RPN(const RPN& other) { (void)other; }
RPN& RPN::operator=(const RPN& other) { (void)other; return *this; }
RPN::~RPN() {}

static bool isOperatorChar(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool RPN::evaluate(const std::string& expr, int& outResult) const {
    std::istringstream iss(expr.c_str());
    std::string tok;
    std::stack<int> st;

    while (iss >> tok) {
        if (tok.size() == 1 && tok[0] >= '0' && tok[0] <= '9') {
            int v = tok[0] - '0';
            st.push(v);
        }
        else if(tok.size() == 1 && isOperatorChar(tok[0]))
        {
            if (st.size() < 2)
                return false;
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int r = 0;
            switch (tok[0]) {
                case '+': r = a + b; break;
                case '-': r = a - b; break;
                case '*': r = a * b; break;
                case '/':
                    if (b == 0) return false;
                    r = a / b; break;
                default: return false;
            }
            st.push(r);
        }
        else 
        {
            return false;
        }
    }

    if (st.size() != 1) 
        return false;
    outResult = st.top();
    return true;
}
