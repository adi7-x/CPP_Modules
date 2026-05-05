#include"Span.hpp"

#include <stdexcept>
#include <iostream>
#include <algorithm>

Span::Span() : maxSize(0) {}

Span::Span(unsigned int N): maxSize(N) {}

Span::Span(const Span& other) : maxSize(other.maxSize), numbers(other.numbers) {}

Span& Span::operator=(const Span& other){
    if(this!=&other)
    {
        maxSize = other.maxSize;
        numbers = other.numbers;
    }
    return(*this);
}

Span::~Span() {}

void Span::addNumber(int value)
{
    if(numbers.size() >= maxSize)
    {
        throw std::runtime_error("Span is full");
    }
    numbers.push_back(value);
    // std::cout << value << std::endl;
}

int Span::shortestSpan() const{
    if (numbers.size() < 2)
        throw std::runtime_error("just 1 numbers !!!");
    
    std::vector<int> tmp(numbers);
    std::sort(tmp.begin(), tmp.end());

    int minSpan = tmp[1] - tmp[0];

    for (size_t i = 1; i < tmp.size(); i++)
    {
        int diff = tmp[i] - tmp[i - 1];
        if(diff < minSpan)
            minSpan = diff;
    }
    return(minSpan);
}

int Span::longestSpan() const{
     if (numbers.size() < 2)
        throw std::runtime_error("just 1 numbers !!!");
    
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    int maxSpan = max - min;
    return(maxSpan);
}
