#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iterator>


class Span{
    private:
        unsigned int maxSize;
        std::vector<int> numbers;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int value);

        int shortestSpan() const;
        int longestSpan() const;
        
        template <typename IT>
        void addRange(IT begin, IT end)
        {
            if(numbers.size() + std::distance(begin, end) > maxSize)
                throw std::runtime_error("Error overflow");
            
            numbers.insert(numbers.end(), begin, end);
        }
};


#endif