#include "PmergeMe.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>
#include <sys/time.h>

static bool parsePositiveInt(const std::string& s, int& out) {
    if (s.empty()) return false;
    for (std::string::size_type i = 0; i < s.size(); ++i) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    std::istringstream iss(s);
    long val;
    iss >> val;
    if (!iss || !iss.eof()) return false;
    if (val <= 0 || val > 2147483647L) return false;
    out = static_cast<int>(val);
    return true;
}

static long long nowMicros() {
    struct timeval tv;
    gettimeofday(&tv, 0);
    return (long long)tv.tv_sec * 1000000LL + (long long)tv.tv_usec;
}

static void printSequence(const std::vector<int>& v) {
    for (std::vector<int>::size_type i = 0; i < v.size(); ++i) {
        if (i) std::cout << " ";
        std::cout << v[i];
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> input;
    input.reserve(argc - 1);
    for (int i = 1; i < argc; ++i) {
        int val;
        if (!parsePositiveInt(argv[i], val)) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        input.push_back(val);
    }

    // Before
    std::cout << "Before: ";
    printSequence(input);

    PmergeMe sorter;

    // Vector timing
    long long startVec = nowMicros();
    std::vector<int> vec(input.begin(), input.end());
    sorter.sortVector(vec);
    long long endVec = nowMicros();

    // Deque timing
    long long startDeq = nowMicros();
    std::deque<int> deq(input.begin(), input.end());
    sorter.sortDeque(deq);
    long long endDeq = nowMicros();

    // After (from vector)
    std::cout << "After: ";
    printSequence(vec);

    // Times
    std::cout.setf(std::ios::fixed);
    std::cout.precision(5);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : "
              << (double)(endVec - startVec) << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : "
              << (double)(endDeq - startDeq) << " us" << std::endl;

    return 0;
}
