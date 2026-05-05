#include "Span.hpp"

#include <stdexcept>
#include <iostream>
#include <algorithm>

int main()
{
    try{

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    // sp.addNumber(11);
    std::cout << "Short_Span : " << sp.shortestSpan() << std::endl;
    std::cout << "Long_Span : " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e){
        std::cout<< e.what() << std::endl;
    }
    
    // Span sp(5);

    // std::vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);


    // // sp.addRange(v.begin(), v.end());

    // std::cout << "Short_Span : " << sp.shortestSpan() << std::endl;
    // std::cout << "Long_Span : " << sp.longestSpan() << std::endl;
    
    return 0;
}