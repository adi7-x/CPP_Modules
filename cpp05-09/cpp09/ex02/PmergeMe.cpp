#include "PmergeMe.hpp"
#include <cstddef>
#include <utility>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe&) {}
PmergeMe& PmergeMe::operator=(const PmergeMe&) { return *this; }
PmergeMe::~PmergeMe() {}

// Binary insertion for vector
void PmergeMe::insertIntoVectorSorted(std::vector<int>& arr, int value) const {
    std::vector<int>::size_type left = 0;
    std::vector<int>::size_type right = arr.size();
    while (left < right) {
        std::vector<int>::size_type mid = left + (right - left) / 2;
        if (value <= arr[mid]) right = mid; else left = mid + 1;
    }
    arr.insert(arr.begin() + left, value);
}

// Binary insertion for deque
void PmergeMe::insertIntoDequeSorted(std::deque<int>& arr, int value) const {
    std::deque<int>::size_type left = 0;
    std::deque<int>::size_type right = arr.size();
    while (left < right) {
        std::deque<int>::size_type mid = left + (right - left) / 2;
        if (value <= arr[mid]) right = mid; else left = mid + 1;
    }
    arr.insert(arr.begin() + left, value);
}

// Ford–Johnson (merge-insert) for vector
void PmergeMe::sortVector(std::vector<int>& data) const {
    if (data.size() < 2) return;

    //Pairing
    std::vector< std::pair<int,int> > pairs; // (big, small)
    bool hasStraggler = (data.size() % 2) != 0;
    int straggler = 0;
    for (std::vector<int>::size_type i = 0; i + 1 < data.size(); i += 2) {
        int a = data[i];
        int b = data[i + 1];
        if (a > b) { int t = a; a = b; b = t; }
        pairs.push_back(std::pair<int,int>(b, a));
    }
    if (hasStraggler) {
        straggler = data.back();
    }

    //Sort pairs by big using insertion sort
    for (std::vector< std::pair<int,int> >::size_type i = 1; i < pairs.size(); ++i) {
        std::pair<int,int> key = pairs[i];
        std::vector< std::pair<int,int> >::size_type j = i;
        while (j > 0 && pairs[j - 1].first > key.first) {
            pairs[j] = pairs[j - 1];
            --j;
        }
        pairs[j] = key;
    }

    //Build main chain from bigs, pending from smalls
    std::vector<int> mainChain;
    mainChain.reserve(pairs.size());
    std::vector<int> pendings;
    pendings.reserve(pairs.size());
    for (std::vector< std::pair<int,int> >::size_type i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pendings.push_back(pairs[i].second);
    }

    // Insert first pending
    if (!pendings.empty()) {
        insertIntoVectorSorted(mainChain, pendings[0]);
    }

    //Compute Jacobsthal numbers to determine insertion order
    std::vector<std::size_t> jac; jac.push_back(1);
    while (true) {
        std::size_t n = jac.size();
        std::size_t next;
        if (n == 1) next = 3; // J2 = J1 + 2*J0 = 1 + 0 = 1 (but we want usable order: 1,3,5,...)
        else {
            // Build actual Jacobsthal sequence Jn = Jn-1 + 2*Jn-2 using our usable values
            std::size_t jn_1 = jac[n - 1];
            std::size_t jn_2 = (n >= 2 ? jac[n - 2] : 0);
            next = jn_1 + 2 * jn_2;
        }
        if (next > pendings.size()) break;
        jac.push_back(next);
    }

    //Insert blocks in descending order within each Jacobsthal step
    std::size_t prev = 1;
    for (std::vector<std::size_t>::size_type idx = 0; idx < jac.size(); ++idx) {
        std::size_t j = jac[idx];
        if (j > pendings.size()) break;
        for (std::size_t k = j; k > prev; --k) {
            insertIntoVectorSorted(mainChain, pendings[k - 1]);
        }
        prev = j;
    }

    for (std::size_t k = pendings.size(); k > prev; --k) {
        insertIntoVectorSorted(mainChain, pendings[k - 1]);
    }


    if (hasStraggler) {
        insertIntoVectorSorted(mainChain, straggler);
    }


    data = mainChain;
}

// Ford–Johnson for deque
void PmergeMe::sortDeque(std::deque<int>& data) const {
    if (data.size() < 2) return;


    std::deque< std::pair<int,int> > pairs;
    bool hasStraggler = (data.size() % 2) != 0;
    int straggler = 0;
    for (std::deque<int>::size_type i = 0; i + 1 < data.size(); i += 2) {
        int a = data[i];
        int b = data[i + 1];
        if (a > b) { int t = a; a = b; b = t; }
        pairs.push_back(std::pair<int,int>(b, a));
    }
    if (hasStraggler) {
        straggler = data.back();
    }


    for (std::deque< std::pair<int,int> >::size_type i = 1; i < pairs.size(); ++i) {
        std::pair<int,int> key = pairs[i];
        std::deque< std::pair<int,int> >::size_type j = i;
        while (j > 0 && pairs[j - 1].first > key.first) {
            pairs[j] = pairs[j - 1];
            --j;
        }
        pairs[j] = key;
    }

    std::deque<int> mainChain;
    std::deque<int> pendings;
    for (std::deque< std::pair<int,int> >::size_type i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pendings.push_back(pairs[i].second);
    }

    if (!pendings.empty()) {
        insertIntoDequeSorted(mainChain, pendings[0]);
    }

    std::deque<std::size_t> jac; jac.push_back(1);
    while (true) {
        std::size_t n = jac.size();
        std::size_t next;
        if (n == 1) next = 3;
        else {
            std::size_t jn_1 = jac[n - 1];
            std::size_t jn_2 = (n >= 2 ? jac[n - 2] : 0);
            next = jn_1 + 2 * jn_2;
        }
        if (next > pendings.size()) break;
        jac.push_back(next);
    }

    std::size_t prev = 1;
    for (std::deque<std::size_t>::size_type idx = 0; idx < jac.size(); ++idx) {
        std::size_t j = jac[idx];
        if (j > pendings.size()) break;
        for (std::size_t k = j; k > prev; --k) {
            insertIntoDequeSorted(mainChain, pendings[k - 1]);
        }
        prev = j;
    }
    for (std::size_t k = pendings.size(); k > prev; --k) {
        insertIntoDequeSorted(mainChain, pendings[k - 1]);
    }

    if (hasStraggler) {
        insertIntoDequeSorted(mainChain, straggler);
    }
    
    data.assign(mainChain.begin(), mainChain.end());
}
