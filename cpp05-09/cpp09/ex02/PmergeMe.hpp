#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe&);
    PmergeMe& operator=(const PmergeMe&);
    ~PmergeMe();

    void sortVector(std::vector<int>& data) const;
    void sortDeque(std::deque<int>& data) const;

private:
    void insertIntoVectorSorted(std::vector<int>& arr, int value) const;
    void insertIntoDequeSorted(std::deque<int>& arr, int value) const;
};

#endif
