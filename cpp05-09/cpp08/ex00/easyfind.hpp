#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <exception>
#include <iostream>

class NotFoundExecption : public std::exception {
    public:
        const char* what() const throw() {
            return("Element Not Found!");
        }
};

template <typename T>
typename T::const_iterator easyfind(const T& container, int value){
    typename T::const_iterator it;

    it = std::find(container.begin(), container.end(), value);

    if(it == container.end())
        throw NotFoundExecption();
    return(it);
}

#endif