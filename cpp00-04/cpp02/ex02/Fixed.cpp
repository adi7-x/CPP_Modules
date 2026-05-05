#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) {
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = i << _fractionalBits;
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _fixedPointValue = other.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const {
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& other) const {
    return _fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const {
    return _fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const {
    return _fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const {
    return _fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const {
    return _fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const {
    return _fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(_fixedPointValue + other._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(_fixedPointValue - other._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    int64_t temp = static_cast<int64_t>(_fixedPointValue) * static_cast<int64_t>(other._fixedPointValue);
    result.setRawBits(temp >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other._fixedPointValue == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        exit(1);
    }
    Fixed result;
    int64_t temp = static_cast<int64_t>(_fixedPointValue) << _fractionalBits;
    result.setRawBits(temp / other._fixedPointValue);
    return result;
}

Fixed& Fixed::operator++() {
    ++_fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    --_fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}
